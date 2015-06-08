/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:57:20 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/30 09:50:41 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>
#include <stdlib.h>

static int	check_readdir(t_sh *sh, DIR *dirp)
{
	struct dirent	*sdir;
	char			*tmp;

	while ((sdir = readdir(dirp)))
	{
		tmp = dirent_to_str(sdir->d_name, sdir->d_namlen);
		if ((ft_strequ(tmp, sh->cmd[0])))
			return (free(tmp), 1);
		free(tmp);
	}
	return (0);
}

static int	is_in_paths(t_sh *sh, char **paths)
{
	DIR		*dirp;
	int		i;

	i = 0;
	while (paths[i])
	{
		if (!(dirp = opendir(paths[i])))
			return (0);
		if (check_readdir(sh, dirp))
		{
			if (paths[i][ft_strlen(paths[i]) - 1] != '/')
				paths[i] = ft_strjoin(paths[i], "/");
			sh->path_cmd = ft_strjoin(paths[i], sh->cmd[0]);
			return (1);
		}
		if (closedir(dirp))
			return (0);
		i++;
	}
	return (0);
}

static int	is_a_bdin(char *cmd)
{
	if (ft_strequ("cd", cmd) || ft_strequ("setenv", cmd) ||
		ft_strequ("unsetenv", cmd) || ft_strequ("exit", cmd) ||
		ft_strequ("env", cmd) || ft_strequ("chdir", cmd) ||
		ft_strequ("echo", cmd) || ft_strequ("pwd", cmd)
		|| ft_strequ("encrypt", cmd) || ft_strequ("decrypt", cmd)
		|| ft_strequ("sort", cmd) || ft_strequ("rand", cmd))
		return (1);
	return (0);
}

static int	path_is_empty(t_sh *sh, char **paths)
{
	if (is_a_bdin(sh->cmd[0]))
		return (free(paths), 2);
	if (sh->cmd[0])
		return (sh->path_cmd = ft_strdup(sh->cmd[0]), 1);
	return (free(paths), 0);
}

int			check_the_cmd(t_sh *sh)
{
	char		**paths;
	const char	*path = search_in_envp(sh, "PATH");

	if (path)
		paths = ft_strsplit(path, ':');
	else
		paths = ft_strsplit("/bin/:/usr/bin/", ':');
	if (path && !path[0])
		return (path_is_empty(sh, paths));
	if (sh->cmd[0])
		if (ft_strchr(sh->cmd[0], '/'))
			return (sh->path_cmd = ft_strdup(sh->cmd[0]), 1);
	if (is_a_bdin(sh->cmd[0]))
		return (free(paths), 2);
	if (is_in_paths(sh, paths))
		return (free(paths), 1);
	return (free(paths), 0);
}

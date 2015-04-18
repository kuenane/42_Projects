/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 08:32:30 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/23 09:27:42 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <libft.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define DONT_EXIST -1
#define NOT_A_DIR -2
#define BAD_PERM -3

static int	try_the_path(char *path)
{
	struct stat		l_s;

	if (lstat(path, &l_s) < 0)
		return (DONT_EXIST);
	if (!(S_ISDIR(l_s.st_mode)))
		return (NOT_A_DIR);
	if (!(l_s.st_mode & (1 << (9 - 3))))
		return (BAD_PERM);
	return (0);
}

int			check_the_path(t_sh *sh, char *str)
{
	char	*path;
	char	*tmp;
	int		ret;

	path = ft_strdup(str);
	if (path[0] != '/')
	{
		tmp = ft_strdup(search_in_envp(sh, "PWD"));
		if (tmp[ft_strlen(tmp) - 1] != '/')
			tmp = ft_strjoin_free(tmp, "/");
		path = ft_strjoin_free_s2(tmp, path);
		free(tmp);
	}
	ret = try_the_path(path);
	free(path);
	if (ret)
		return (print_error_path_access(sh->cmd[1], ret), -1);
	return (0);
}

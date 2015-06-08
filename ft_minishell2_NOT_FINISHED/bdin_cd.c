/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:44:37 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:42:24 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>

static t_sh		*update_pwd(t_sh *sh)
{
	char	buf[PATH_MAX + 1];
	char	*tmp;
	int		i;

	i = 0;
	if (!(search_in_envp(sh, "OLDPWD")))
		sh->env = add_str_to_tab(sh->env, "OLDPWD=");
	while (sh->env[i] && ft_strncmp(sh->env[i], "PWD=", 4))
		i++;
	if (sh->env[i] == '\0')
		return (NULL);
	tmp = ft_strjoin("OLD", sh->env[i]);
	sh->env[i] = ft_strjoin("PWD=", getcwd(buf, PATH_MAX + 1));
	i = 0;
	while (sh->env[i] && ft_strncmp(sh->env[i], "OLDPWD", 6))
		i++;
	if (sh->env[i] == '\0')
		return (NULL);
	sh->env[i] = ft_strdup(tmp);
	free(tmp);
	return (sh);
}

static int		change_directory(t_sh *sh, char *path)
{
	if (!path)
		return (ft_putendl_fd("ft_minishell: directory not set", 2), 1);
	if (check_the_path(sh, path))
		return (1);
	if (chdir(path))
		return (ft_putendl_fd("chdir error", 2), 1);
	if (!(sh = update_pwd(sh)))
		return (ft_putendl_fd("error when updating env", 2), 1);
	return (0);
}

int				bdin_cd(t_sh *sh)
{
	if (!sh->cmd[1])
		return (change_directory(sh, search_in_envp(sh, "HOME")));
	if (ft_strequ("-", sh->cmd[1]))
		return (change_directory(sh, search_in_envp(sh, "OLDPWD")));
	return (change_directory(sh, sh->cmd[1]));
}

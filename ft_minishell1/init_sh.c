/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:57:06 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/30 08:55:23 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/param.h>

static void		del_space(t_sh *sh)
{
	int		i;
	char	*tmp;

	i = 0;
	while (sh->cmd[i])
	{
		tmp = ft_strtrim(sh->cmd[i]);
		free(sh->cmd[i]);
		sh->cmd[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}

void			check_if_pwd(t_sh *sh)
{
	char	buf[PATH_MAX + 1];
	int		i;

	if ((search_in_envp(sh, "PWD")))
		return ;
	if (!(sh->env = add_str_to_tab(sh->env, "PWD=")))
	{
		ft_putendl_fd("error when setting $PWD", 2);
		return (exit(EXIT_FAILURE));
	}
	i = 0;
	while (ft_strncmp(sh->env[i], "PWD=", 4))
		i++;
	free(sh->env[i]);
	sh->env[i] = ft_strjoin(sh->env[i], getcwd(buf, PATH_MAX + 1));
}

void			init_after_gnl(t_sh *sh, char *line)
{
	sh->cmd = ft_strsplit(line, ' ');
	del_space(sh);
	free(line);
	check_if_pwd(sh);
}

void			init_struct_sh(t_sh *sh)
{
	extern char	**environ;

	sh->env = cp_env_tab(environ);
	sh->path_cmd = NULL;
	sh = manage_shlvl(sh);
}

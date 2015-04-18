/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:49:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/28 14:35:47 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <libft.h>
#include <stdlib.h>

static int		print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
	return (0);
}

static t_sh		*parse_and_put_env(t_sh *sh)
{
	t_sh	*newsh;

	newsh = cp_t_sh(sh);
	del_str_in_tab(newsh->cmd, "env");
	if (newsh->cmd[0][0] == '-')
	{
		if (ft_strcmp(newsh->cmd[0], "-i"))
			return (ft_putendl_fd("env: invalid option", 2), NULL);
		newsh->env = (char**)verified_malloc(sizeof(char*) * 1);
		newsh->env[0] = NULL;
		del_str_in_tab(newsh->cmd, "-i");
	}
	else
		newsh->env = cp_env_tab(sh->env);
	return (newsh);
}

static void		interpret_ret(t_sh *newsh, int ret)
{
	if (ret == 1)
		cmd_detected(newsh);
	else if (ret == 2)
		bdin_detected(newsh);
	else
		print_error_bad_cmd(newsh->cmd[0], ret);
}

int				bdin_env(t_sh *sh)
{
	t_sh	*newsh;
	int		ret;

	if (!sh->cmd[1])
		return (print_env(sh->env));
	if (!(newsh = parse_and_put_env(sh)))
		return (1);
	while (newsh->cmd[0] && ft_strchr(newsh->cmd[0], '='))
	{
		if (search_in_chartab(newsh->env, newsh->cmd[0]))
			del_str_in_tab(newsh->env, newsh->cmd[0]);
		newsh->env = add_str_to_tab(newsh->env, newsh->cmd[0]);
		del_str_in_tab(newsh->cmd, newsh->cmd[0]);
	}
	if (!newsh->cmd[0])
		return (print_env(newsh->env));
	check_if_pwd(newsh);
	ret = check_the_cmd(newsh);
	interpret_ret(newsh, ret);
	return (free(newsh), 0);
}

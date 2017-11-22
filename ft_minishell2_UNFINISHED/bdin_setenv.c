/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:48:44 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/28 15:13:19 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>
#include <stdlib.h>

static int	check_args(char **cmd)
{
	if (!cmd[1])
		return (ft_putendl_fd("usage: setenv [name] [value]", 2), 1);
	if (ft_strchr(cmd[1], '='))
		return (ft_putendl_fd("setenv: syntax error", 2), 1);
	return (0);
}

int			bdin_setenv(t_sh *sh)
{
	char	*tmp;

	if (check_args(sh->cmd))
		return (1);
	if ((search_in_envp(sh, sh->cmd[1])))
		del_str_in_tab(sh->env, sh->cmd[1]);
	tmp = ft_strdup(sh->cmd[1]);
	if (sh->cmd[1][ft_strlen(sh->cmd[1] - 1)] != '=')
		tmp = ft_strjoin_free(sh->cmd[1], "=");
	if (sh->cmd[2])
		tmp = ft_strjoin_free(tmp, sh->cmd[2]);
	sh->env = add_str_to_tab(sh->env, tmp);
	free(tmp);
	return (0);
}

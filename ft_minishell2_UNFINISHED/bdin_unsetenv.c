/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:49:05 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:48:57 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>

int		bdin_unsetenv(t_sh *sh)
{
	int		i;

	i = 1;
	if (!sh->cmd[i])
		return (ft_putendl("usage: unsetenv [name]"), 1);
	while (sh->cmd[i])
	{
		if ((search_in_envp(sh, sh->cmd[i])))
			del_str_in_tab(sh->env, sh->cmd[i]);
		ft_putstr(sh->cmd[i]);
		ft_putendl(" unset");
		i++;
	}
	return (0);
}

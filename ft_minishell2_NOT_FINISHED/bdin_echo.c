/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 09:38:42 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:45:33 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>

int		bdin_echo(t_sh *sh)
{
	int		i;
	int		n_opt;

	i = 1;
	n_opt = 0;
	if (ft_strequ(sh->cmd[i], "-n"))
	{
		i++;
		n_opt++;
	}
	while (sh->cmd[i])
	{
		ft_putstr(sh->cmd[i]);
		i++;
		if (sh->cmd[i])
			ft_putchar(' ');
	}
	if (!n_opt)
		ft_putchar('\n');
	return (0);
}

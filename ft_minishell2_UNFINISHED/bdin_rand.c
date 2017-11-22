/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_rand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 09:38:42 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:45:33 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>

#define ERR_INPUT_MSG "usage: rand [[min] max]"

static int		is_nb_invalid(char *str)
{
	int		len;

	if (!str[0])
		return (ft_putendl_fd(ERR_INPUT_MSG, 2), 1);
	len = 0;
	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (str[len])
	{
		if (!ft_isdigit(str[len]) || len > 10)
			return (ft_putendl_fd(ERR_INPUT_MSG, 2), 1);
		len++;
	}
	if (len > 10 || (len == 10 &&
	ft_strcmp(str, "2147483647") > 0))
		return (ft_putendl_fd(ERR_INPUT_MSG, 2), 1);
	return (0);
}

int				bdin_rand(t_sh *sh)
{
	int		min;
	int		max;

	if (!sh->cmd[1])
	{
		ft_putnbr(ft_random(0, 2147483647));
		return (ft_putchar('\n'), 1);
	}
	if (is_nb_invalid(sh->cmd[1]))
		return (0);
	if (sh->cmd[2])
	{
		if (is_nb_invalid(sh->cmd[2]))
			return (0);
		min = ft_atoi(sh->cmd[1]);
		max = ft_atoi(sh->cmd[2]);
	}
	else
	{
		min = 0;
		max = ft_atoi(sh->cmd[1]);
	}
	ft_putnbr(ft_random(min, max));
	return (ft_putchar('\n'), 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:42:39 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/16 10:10:12 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>

static int	give_sign(char *str, int pos)
{
	int		sign;

	sign = 1;
	pos--;
	while (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			sign *= -1;
		pos--;
	}
	return (sign);
}

int			ft_getnbr(char *str, int pos)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = give_sign(str, pos);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		nb = (nb * 10) + (str[pos] - '0');
		pos++;
	}
	return (nb *= sign);
}

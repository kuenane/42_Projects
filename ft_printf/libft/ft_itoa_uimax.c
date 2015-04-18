/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uimax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 08:27:34 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 08:10:48 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>

static int	ft_nb_digit(uintmax_t n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_uimax(uintmax_t n)
{
	int		nb_digit;
	char	*str;

	nb_digit = ft_nb_digit(n);
	if (!(str = ft_strnew(nb_digit)))
		return (NULL);
	nb_digit--;
	while (nb_digit >= 0)
	{
		if (str[nb_digit] == '-')
			return (str);
		str[nb_digit] = (n % 10) + 48;
		n = n / 10;
		nb_digit--;
	}
	return (str);
}

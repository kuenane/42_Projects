/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 10:56:12 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/19 12:10:57 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	ft_nb_digit(long long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_l(long long n)
{
	int		nb_digit;
	char	*str;

	nb_digit = ft_nb_digit(n);
	if (!(str = ft_strnew(nb_digit)))
		return (NULL);
	if (n < -9223372036854775807)
		return (ft_strcpy(str, "-9223372036854775808"));
	nb_digit--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
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

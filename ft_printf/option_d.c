/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 17:08:43 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 16:19:59 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

static char		*ft_itoa_va_arg(int *tab, va_list ap)
{
	if (!tab[10])
	{
		if (!tab[11])
		{
			if (!tab[9])
			{
				if (!tab[8])
					return (ft_itoa((int)va_arg(ap, int)));
				if (tab[8] == 1)
					return (ft_itoa((short int)va_arg(ap, int)));
				return (ft_itoa((char)va_arg(ap, int)));
			}
			if (tab[9])
				return (ft_itoa_imax((intmax_t)va_arg(ap, intmax_t)));
		}
		if (tab[11])
			return (ft_itoa_ll((long long)va_arg(ap, long long)));
	}
	else if (tab[10] == 1)
		return (ft_itoa_l((long long)va_arg(ap, long long)));
	return (ft_itoa_ll((long long)va_arg(ap, long long)));
}

static char		*option_plus_and_space(char *str, int *tab)
{
	if (tab[2] && str[0] != '-')
		return (ft_strjoin_free_s2("+", str));
	if (tab[5] && str[0] != '-' && str[0] != '+')
		return (ft_strjoin_free_s2(" ", str));
	return (str);
}

static char		*contain_tab7(char *str, int *tab)
{
	while ((int)ft_strlen(str) < tab[7] && str[0] != '-')
		str = ft_strjoin_free_s2("0", str);
	while ((int)ft_strlen(str) < (tab[7] + 1) && str[0] == '-')
	{
		str[0] = '0';
		str = ft_strjoin_free_s2("-", str);
	}
	return (str);
}

int				option_d(int *tab, va_list ap)
{
	char				*str;
	unsigned long long	len;

	str = ft_itoa_va_arg(tab, ap);
	if (str[0] == '0' && !str[1] && !tab[7] && !tab[3])
		return (0);
	str = option_plus_and_space(str, tab);
	str = contain_tab7(str, tab);
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

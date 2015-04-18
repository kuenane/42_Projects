/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 08:07:18 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 16:19:43 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>

#define U_I unsigned int
#define U_S unsigned short
#define U_C unsigned char
#define U_L unsigned long
#define U_L_L unsigned long long

static char		*ft_itoa_va_arg(int *tab, va_list ap)
{
	if (!tab[10])
	{
		if (!tab[11])
		{
			if (!tab[9])
			{
				if (!tab[8])
					return (ft_itoa_ui((U_I)va_arg(ap, U_I)));
				if (tab[8] == 1)
					return (ft_itoa_ui((U_S)va_arg(ap, U_I)));
				return (ft_itoa_ui((U_C)va_arg(ap, U_I)));
			}
			if (tab[9])
				return (ft_itoa_ull((U_L_L)va_arg(ap, uintmax_t)));
		}
		if (tab[11])
			return (ft_itoa_st((size_t)va_arg(ap, size_t)));
	}
	if (tab[10] == 1)
		return (ft_itoa_ul((U_L)va_arg(ap, U_L)));
	return (ft_itoa_ull((U_L_L)va_arg(ap, U_L_L)));
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

int				option_u(int *tab, va_list ap)
{
	char				*str;
	unsigned long long	len;

	str = ft_itoa_va_arg(tab, ap);
	if (str[0] == '0' && !str[1] && !tab[7] && !tab[3])
		return (0);
	str = contain_tab7(str, tab);
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

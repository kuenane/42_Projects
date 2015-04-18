/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:27:23 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 16:27:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define U_I unsigned int
#define U_S unsigned short
#define U_C unsigned char
#define S_T size_t
#define SS_T ssize_t
#define U_L unsigned long
#define U_L_L unsigned long long
#define HLOW "0123456789abcdef"
#define HUP "0123456789ABCDEF"

static char		*x_is_lowcase(int *tab, va_list ap)
{
	if (!tab[10])
	{
		if (!tab[11])
		{
			if (!tab[9])
			{
				if (!tab[8])
					return (convert_ui_to_other((U_I)va_arg(ap, U_I), HLOW));
				if (tab[8] == 1)
					return (convert_us_to_other((U_S)va_arg(ap, U_I), HLOW));
				return (convert_uc_to_other((U_C)va_arg(ap, U_I), HLOW));
			}
			if (tab[9])
				return (convert_ull_to_other((U_L_L)va_arg(ap, U_L_L), HLOW));
		}
		if (tab[11])
			return (convert_st_to_other((S_T)va_arg(ap, size_t), HLOW));
	}
	if (tab[10] == 1)
		return (convert_ul_to_other((U_L)va_arg(ap, U_L), HLOW));
	return (convert_ull_to_other((U_L_L)va_arg(ap, U_L_L), HLOW));
}

static char		*x_is_upcase(int *tab, va_list ap)
{
	if (tab[10] == 424242)
	{
		if (!tab[11])
		{
			if (!tab[9])
			{
				if (!tab[8])
					return (convert_ui_to_other((U_I)va_arg(ap, U_I), HUP));
				if (tab[8] == 1)
					return (convert_us_to_other((U_S)va_arg(ap, U_I), HUP));
				return (convert_uc_to_other((U_C)va_arg(ap, U_I), HUP));
			}
			if (tab[9])
				return (convert_ull_to_other((U_L_L)va_arg(ap, U_L_L), HUP));
		}
		if (tab[11])
			return (convert_st_to_other((S_T)va_arg(ap, size_t), HUP));
	}
	if (tab[10] == 424243)
		return (convert_ul_to_other((U_L)va_arg(ap, U_L), HUP));
	return (convert_ull_to_other((U_L_L)va_arg(ap, U_L_L), HUP));
}

static char		*add_0x_to_str(char *str, int *tab)
{
	if (tab[10] < 424242 && tab[3] && str[0] != '0' && str[1])
		return (ft_strjoin_free_s2("0x", str));
	if (tab[10] >= 424242 && tab[3] && str[0] != '0' && str[1])
		return (ft_strjoin_free_s2("0X", str));
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

int				option_x(int *tab, va_list ap)
{
	char				*str;
	unsigned long long	len;

	if (tab[10] < 424242)
		str = x_is_lowcase(tab, ap);
	else
		str = x_is_upcase(tab, ap);
	if (str[0] == '0' && !str[1] && !tab[7])
		return (0);
	str = add_0x_to_str(str, tab);
	str = contain_tab7(str, tab);
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

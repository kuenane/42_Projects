/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 14:50:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 16:18:45 by wide-aze         ###   ########.fr       */
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
#define BOCT "01234567"

static char		*call_convert_va_arg(int *tab, va_list ap)
{
	if (!tab[10])
	{
		if (!tab[11])
		{
			if (!tab[9])
			{
				if (!tab[8])
					return (convert_ui_to_other((U_I)va_arg(ap, U_I), BOCT));
				if (tab[8] == 1)
					return (convert_ui_to_other((U_S)va_arg(ap, U_I), BOCT));
				return (convert_ui_to_other((U_C)va_arg(ap, U_I), BOCT));
			}
			if (tab[9])
				return (convert_ull_to_other((U_L_L)va_arg(ap, U_L_L), BOCT));
		}
		if (tab[11])
			return (convert_st_to_other((S_T)va_arg(ap, S_T), BOCT));
	}
	else if (tab[10] == 1)
		return (convert_ul_to_other((U_L)va_arg(ap, U_L), BOCT));
	return (convert_ull_to_other((U_L_L)va_arg(ap, U_L_L), BOCT));
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

int				option_o(int *tab, va_list ap)
{
	char				*str;
	unsigned long long	len;

	str = call_convert_va_arg(tab, ap);
	if (str[0] == '0' && !str[1] && !tab[7] && !tab[3])
		return (0);
	if (tab[3] && str[0] != '0')
		str = ft_strjoin_free_s2("0", str);
	str = contain_tab7(str, tab);
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

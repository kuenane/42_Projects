/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:45:18 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 14:58:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>

#define U_L unsigned long
#define U_L_L unsigned long long
#define HEXA_UP "0123456789ABCDEF"
#define HEXA_LOW "0123456789abcdef"

static char		*give_converted(int tab10, va_list ap)
{
	if (tab10 < 424242)
	{
		if (tab10 <= 1)
			return (convert_ul_to_other((U_L)va_arg(ap, void*), HEXA_LOW));
		return (convert_ull_to_other((U_L_L)va_arg(ap, void*), HEXA_LOW));
	}
	if (tab10 <= 424243)
		return (convert_ul_to_other((U_L)va_arg(ap, void*), HEXA_UP));
	return (convert_ull_to_other((U_L_L)va_arg(ap, void*), HEXA_UP));
}

int				option_p(int *tab, va_list ap)
{
	char				*str;
	unsigned long long	len;

	str = give_converted(tab[10], ap);
	str = apply_preci_min(str, tab);
	if (tab[10] < 424242)
		str = ft_strjoin("0x", str);
	else if (tab[10] >= 424242)
		str = ft_strjoin("0", str);
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

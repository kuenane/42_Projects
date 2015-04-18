/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 07:30:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/07 09:21:27 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>

#define U_I unsigned int
#define U_L unsigned long
#define U_L_L unsigned long long

int				option_b(int *tab, va_list ap)
{
	char				*str;
	unsigned long long	len;

	if (!tab[10])
		str = convert_ui_to_other((U_I)va_arg(ap, U_I), "01");
	else if (tab[10] == 1)
		str = convert_ul_to_other((U_L)va_arg(ap, U_L), "01");
	else
		str = convert_ull_to_other((U_L_L)va_arg(ap, U_L_L), "01");
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 16:33:16 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 09:43:38 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#define U_C unsigned char

static char		*give_arg(int *tab, va_list ap)
{
	char	tmp[5];
	int		len;

	len = 1;
	if (!tab[10])
		tmp[0] = (U_C)va_arg(ap, unsigned int);
	else
		len = ft_itoa_wchar(tmp, (wchar_t)va_arg(ap, unsigned int));
	tmp[len] = '\0';
	return (ft_strdup(tmp));
}

static int		check_c_tab6(int *tab, char *str)
{
	if (!str[0] && tab[6] == 3)
	{
		if (tab[4])
			return (ft_putstr(Z_Z), ft_putchar(*str), 1);
		return (ft_putstr(SP_SP), ft_putchar(*str), 1);
	}
	return (0);
}

int				option_c(int *tab, va_list ap)
{
	char	*str;
	int		len;

	str = give_arg(tab, ap);
	if (check_c_tab6(tab, str))
		return (3);
	str = apply_width_min(str, tab);
	if (!str[0])
		ft_putchar(*str);
	else
		ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	if (len)
		return (len);
	return (1);
}

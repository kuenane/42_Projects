/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 15:42:22 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 15:33:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdlib.h>

static int	parse_format(char *format, va_list ap, int len)
{
	int		tab[15];

	if (format[0] == '%' && !format[1])
		return (len);
	while (*format)
	{
		if (*format == '%')
		{
			current_option_put_tab(format, tab);
			len += print_current_option(tab, ap, format[tab[13] - 1]);
			format += tab[13];
		}
		else
		{
			ft_putchar(*(format++));
			len++;
		}
	}
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = parse_format((char*)format, ap, 0);
	va_end(ap);
	return (len);
}

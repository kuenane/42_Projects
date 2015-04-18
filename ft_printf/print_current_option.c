/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_current_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 15:09:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/19 16:52:21 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_current_option2(int *tab, va_list ap)
{
	if (tab[12] == 'o')
		return (option_o(tab, ap));
	if (tab[12] == 'O')
		return (tab[10]++, option_o(tab, ap));
	if (tab[12] == 'u')
		return (option_u(tab, ap));
	if (tab[12] == 'U')
		return (tab[10]++, option_u(tab, ap));
	if (tab[12] == 'x')
		return (option_x(tab, ap));
	if (tab[12] == 'X')
		return (tab[10] += 424242, option_x(tab, ap));
	if (tab[12] == 'c')
		return (option_c(tab, ap));
	if (tab[12] == 'C')
		return (tab[10]++, option_c(tab, ap));
	if (tab[12] == 'b')
		return (option_b(tab, ap));
	if (tab[12] == 'B')
		return (tab[10]++, option_b(tab, ap));
	return (0);
}

int			print_current_option(int *tab, va_list ap, char c)
{
	if (tab[12] == '%')
		return (option_percent(tab));
	if (tab[12] == 4242)
		return (option_4242(tab, c));
	if (tab[12] == 's')
		return (option_s(tab, ap));
	if (tab[12] == 'S')
		return (tab[10]++, option_s(tab, ap));
	if (tab[12] == 'p')
		return (option_p(tab, ap));
	if (tab[12] == 'P')
		return (tab[10] += 424242, option_p(tab, ap));
	if (tab[12] == 'd' || tab[12] == 'i')
		return (option_d(tab, ap));
	if (tab[12] == 'D')
		return (tab[10]++, option_d(tab, ap));
	return (print_current_option2(tab, ap));
}

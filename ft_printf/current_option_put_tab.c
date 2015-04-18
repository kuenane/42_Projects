/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_option_put_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 08:49:51 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 16:21:29 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_tab(char *format, int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	tab[6] = 0;
	tab[7] = 0;
	tab[8] = 0;
	tab[9] = 0;
	tab[10] = 0;
	tab[11] = 0;
	tab[12] = 0;
	tab = current_option_len(format, tab);
}

void			current_option_put_tab(char *s, int *tab)
{
	init_tab(s, tab);
	current_option_put12345(s, tab, 1);
}

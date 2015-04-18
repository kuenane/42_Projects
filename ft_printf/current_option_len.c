/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_option_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 08:53:49 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/19 11:41:23 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

static int	parse_len(char *s, int i)
{
	while (s[i] == '-' || s[i] == '+' || s[i] == '#'
	|| s[i] == '0' || s[i] == ' ')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
	{
		i++;
		while (ft_isdigit(s[i]))
			i++;
	}
	while (s[i] == 'h' || s[i] == 'j' || s[i] == 'l' || s[i] == 'z')
		i++;
	return (i);
}

int			*current_option_len(char *s, int *tab)
{
	int		i;

	i = parse_len(s, 1);
	if (s[i] != 's' && s[i] != 'S' && s[i] != 'p' && s[i] != 'd' &&
	s[i] != 'D' && s[i] != 'i' && s[i] != 'o' && s[i] != 'O' &&
	s[i] != 'u' && s[i] != 'U' && s[i] != 'x' && s[i] != 'X' &&
	s[i] != 'c' && s[i] != 'C' && s[i] != 'b' && s[i] != 'B' &&
	s[i] != 'P' && s[i] != '%')
		tab[14] = 4242;
	else
		tab[14] = 0;
	tab[13] = i + 1;
	return (tab);
}

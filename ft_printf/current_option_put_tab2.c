/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_option_put_tab2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:06:29 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 15:49:23 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		current_option_put12(char c, int *tab)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
	c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
	c == 'c' || c == 'C' || c == 'B' || c == 'b' || c == 'P' || c == '%')
		tab[12] = c;
	else
		tab[12] = 4242;
	if (((c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
	c == 'u' || c == 'U' || c == 'x' || c == 'X') && tab[7] != -424242) ||
	tab[1])
		tab[4] = 0;
	if ((c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
	c == 'u' || c == 'U' || c == 'x' || c == 'X') && tab[7] == -424242)
		tab[7] = 1;
}

static void		current_option_put891011(char *s, int *tab, int i)
{
	while (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 'z')
	{
		if (s[i] == 'h')
			tab[8]++;
		else if (s[i] == 'j')
			tab[9]++;
		else if (s[i] == 'l')
			tab[10]++;
		else
			tab[11]++;
		i++;
	}
	current_option_put12(s[i], tab);
}

static void		current_option_put7(char *s, int *tab, int i)
{
	if (s[i] == '.')
	{
		i++;
		if (ft_isdigit(s[i]))
		{
			if (s[i] == '+')
				i++;
			while (ft_isdigit(s[i]))
			{
				tab[7] = (tab[7] * 10) + (s[i] - '0');
				i++;
			}
		}
	}
	else
		tab[7] = -424242;
	current_option_put891011(s, tab, i);
}

static void		current_option_put6(char *s, int *tab, int i)
{
	while (ft_isdigit(s[i]))
	{
		tab[6] = (tab[6] * 10) + (s[i] - '0');
		i++;
	}
	current_option_put7(s, tab, i);
}

void			current_option_put12345(char *s, int *tab, int i)
{
	while (s[i] == '-' || s[i] == '+' || s[i] == '#' ||
	s[i] == '0' || s[i] == ' ')
	{
		if (s[i] == '-')
			tab[1]++;
		else if (s[i] == '+')
			tab[2]++;
		else if (s[i] == '#')
			tab[3]++;
		else if (s[i] == '0')
			tab[4]++;
		else if (s[i] == ' ')
			tab[5]++;
		i++;
	}
	current_option_put6(s, tab, i);
}

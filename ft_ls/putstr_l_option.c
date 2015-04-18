/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_l_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 17:51:49 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 15:23:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

void	putstr_l_opt(char const *s, size_t max, char l_or_r)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = max - ft_strlen(s);
	if (l_or_r == 'l')
		ft_putstr(s);
	while (i < count)
	{
		ft_putchar(' ');
		i++;
	}
	if (l_or_r == 'r')
		ft_putstr(s);
	ft_putchar(' ');
}

void	putstr_with_one_space(char const *s)
{
	ft_putstr(s);
	ft_putchar(' ');
}

void	putstr_without_last(char *str)
{
	int		i;

	i = 0;
	while (str[i + 1])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 07:53:34 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 11:08:48 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static char		*add_space_right(char *str, int tab6)
{
	while ((int)ft_strlen(str) < tab6)
		str = ft_strjoin(str, " ");
	return (str);
}

static char		*add_space_left(char *str, int tab6)
{
	while ((int)ft_strlen(str) < tab6)
		str = ft_strjoin(" ", str);
	return (str);
}

static char		*add_zero_left(char *str, int tab6)
{
	while ((int)ft_strlen(str) < tab6 && (str[0] == '-' || str[0] == '+' ||
	str[0] == ' '))
	{
		if (str[0] == '-')
			str = ft_strjoin("-", str);
		else if (str[0] == '+')
			str = ft_strjoin("+", str);
		else
			str = ft_strjoin(" ", str);
		str[1] = '0';
	}
	while (ft_strnequ("0x0", str, 3) && (int)ft_strlen(str) < tab6)
	{
		str[0] = 'x';
		str[1] = '0';
		str = ft_strjoin("0", str);
	}
	while ((int)ft_strlen(str) < tab6)
		str = ft_strjoin("0", str);
	return (str);
}

char			*apply_width_min(char *str, int *tab)
{
	if ((int)ft_strlen(str) >= tab[6])
		return (ft_strdup(str));
	if (tab[1])
		return (add_space_right(str, tab[6]));
	if (tab[4])
		return (add_zero_left(str, tab[6]));
	return (add_space_left(str, tab[6]));
}

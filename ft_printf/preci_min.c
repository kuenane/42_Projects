/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:46:22 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 15:49:50 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static char		*add_zero_left(char *str, int tab7)
{
	while ((int)ft_strlen(str) < tab7)
		str = ft_strjoin("0", str);
	return (str);
}

static char		*tronc_str(char *str, int tab7)
{
	char	*new;

	new = ft_strnew(tab7);
	return (ft_strncpy(new, str, tab7));
}

char			*apply_preci_min(char *str, int *tab)
{
	if (tab[7] != -424242)
		if ((int)ft_strlen(str) > tab[7])
			return (tronc_str(str, tab[7]));
	if ((int)ft_strlen(str) < tab[7])
		return (add_zero_left(str, tab[7]));
	return (ft_strdup(str));
}

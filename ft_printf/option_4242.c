/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_4242.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 11:24:04 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/19 16:44:28 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdlib.h>

#define U_C unsigned char

static char		*give_arg(char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	return (ft_strdup(tmp));
}

int				option_4242(int *tab, char c)
{
	char	*str;
	int		len;

	str = give_arg(c);
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

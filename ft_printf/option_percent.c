/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 12:14:21 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/08 12:16:19 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include <stdlib.h>

static char		*give_arg(void)
{
	char	tmp[2];

	tmp[0] = '%';
	tmp[1] = '\0';
	return (ft_strdup(tmp));
}

int				option_percent(int *tab)
{
	char	*str;
	int		len;

	str = give_arg();
	str = apply_width_min(str, tab);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

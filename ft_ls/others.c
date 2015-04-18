/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 09:19:28 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 15:04:49 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

void	if_enabled_no_l(t_read *list, int enabled)
{
	if (enabled)
	{
		if (list->was_lnk == 1)
			putstr_without_last(list->name);
		else
			ft_putstr(list->name);
		ft_putendl(":");
	}
}

void	if_enabled_l(char *name, int enabled)
{
	if (enabled)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enabled.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:04:35 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 13:51:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		give_nb_dirs(t_read *list)
{
	int		nb;

	nb = 0;
	while (list)
	{
		if (list->lopt->rights[0] == 'd')
			nb++;
		list = list->next;
	}
	return (nb);
}

int		give_nb_files(t_read *list)
{
	int		nb;

	nb = 0;
	while (list)
	{
		if (list->lopt->rights[0] != 'd')
			nb++;
		list = list->next;
	}
	return (nb);
}

int		check_if_enabled(t_read *list)
{
	if (give_nb_dirs(list) > 1)
		return (1);
	if (give_nb_dirs(list) == 1 && give_nb_files(list))
		return (1);
	return (0);
}

int		is_last_dir(t_read *list)
{
	while (list)
	{
		if (list->lopt->rights[0] == 'd')
			return (0);
		list = list->next;
	}
	return (1);
}

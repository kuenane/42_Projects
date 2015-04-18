/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lopt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:31:33 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 14:51:38 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <stdlib.h>
#include <sys/stat.h>

void		put_lopt(t_read *list)
{
	while (list)
	{
		list->lopt = (t_lopt*)verified_malloc(sizeof(t_lopt) * 1);
		list->lopt->rights = give_type_and_rights(list);
		list->lopt->links = ft_itoa(list->l_stat->st_nlink);
		list->lopt->usr = give_usr(list);
		list->lopt->gp = give_gp(list);
		list->lopt->size = ft_itoa(list->l_stat->st_size);
		list->lopt->time = give_str_time(list);
		if (S_ISLNK(list->l_stat->st_mode))
			list->lopt->linked = give_linked(list->name, list->path);
		else
			list->lopt->linked = NULL;
		list = list->next;
	}
}

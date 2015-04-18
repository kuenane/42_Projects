/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:00:16 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 14:06:51 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

static size_t		max_links(t_read *list)
{
	size_t		max;

	max = 0;
	while (list)
	{
		if (ft_strlen(list->lopt->links) > max)
			max = ft_strlen(list->lopt->links);
		list = list->next;
	}
	return (max);
}

static size_t		max_usr(t_read *list)
{
	size_t		max;

	max = 0;
	while (list)
	{
		if (ft_strlen(list->lopt->usr) > max)
			max = ft_strlen(list->lopt->usr);
		list = list->next;
	}
	return (max);
}

static size_t		max_gp(t_read *list)
{
	size_t		max;

	max = 0;
	while (list)
	{
		if (ft_strlen(list->lopt->gp) > max)
			max = ft_strlen(list->lopt->gp);
		list = list->next;
	}
	return (max);
}

static size_t		max_size(t_read *list)
{
	size_t		max;

	max = 0;
	while (list)
	{
		if (ft_strlen(list->lopt->size) > max)
			max = ft_strlen(list->lopt->size);
		list = list->next;
	}
	return (max);
}

size_t				*give_max(t_read *list)
{
	size_t		*max;

	max = (size_t*)verified_malloc(sizeof(size_t) * 4);
	max[0] = max_links(list);
	max[1] = max_usr(list);
	max[2] = max_gp(list);
	max[3] = max_size(list);
	return (max);
}

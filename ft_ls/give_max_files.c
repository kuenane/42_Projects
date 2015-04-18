/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_max_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:59:48 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 13:21:17 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

static size_t		max_links(t_read *list)
{
	size_t		max;
	t_read		*current;
	char		*str;

	max = 0;
	current = list;
	while (current)
	{
		str = current->lopt->links;
		if (ft_strlen(str) > max && !current->contents)
			max = ft_strlen(str);
		current = current->next;
	}
	return (max);
}

static size_t		max_usr(t_read *list)
{
	size_t		max;
	t_read		*current;
	char		*str;

	max = 0;
	current = list;
	while (current)
	{
		str = current->lopt->usr;
		if (ft_strlen(str) > max && !current->contents)
			max = ft_strlen(str);
		current = current->next;
	}
	return (max);
}

static size_t		max_gp(t_read *list)
{
	size_t		max;
	t_read		*current;
	char		*str;

	max = 0;
	current = list;
	while (current)
	{
		str = current->lopt->gp;
		if (ft_strlen(str) > max && !current->contents)
			max = ft_strlen(str);
		current = current->next;
	}
	return (max);
}

static size_t		max_size(t_read *list)
{
	size_t		max;
	t_read		*current;
	char		*str;

	max = 0;
	current = list;
	while (current)
	{
		str = current->lopt->size;
		if (ft_strlen(str) > max && !current->contents)
			max = ft_strlen(str);
		current = current->next;
	}
	return (max);
}

size_t				*give_max_files(t_read *list)
{
	size_t		*max;

	max = (size_t*)verified_malloc(sizeof(size_t) * 4);
	max[0] = max_links(list);
	max[1] = max_usr(list);
	max[2] = max_gp(list);
	max[3] = max_size(list);
	return (max);
}

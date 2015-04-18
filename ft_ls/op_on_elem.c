/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:10:38 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 13:27:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <stdlib.h>

t_read		*new_elem(char *name)
{
	t_read		*new;

	new = (t_read *)verified_malloc(sizeof(t_read) * 1);
	new->name = name;
	new->path = NULL;
	new->was_lnk = 0;
	new->contents = NULL;
	new->next = NULL;
	new->l_stat = NULL;
	return (new);
}

t_read		*add_elem(t_read *list, char *name)
{
	t_read		*tmp;
	t_read		*current;

	tmp = new_elem(name);
	if (!(list))
		return (tmp);
	current = list;
	while (current->next)
		current = current->next;
	current->next = tmp;
	return (list);
}

t_read		**remove_elem(t_read **list, char *name)
{
	t_read	*tmp;
	t_read	*l_stat;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->next->name == name)
		{
			l_stat = tmp->next;
			tmp->next = tmp->next->next;
			free(l_stat);
		}
		else
			tmp = tmp->next;
	}
	if ((*list)->name == name)
		*list = (*list)->next;
	return (list);
}

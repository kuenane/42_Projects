/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:38:13 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 15:27:29 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <sys/stat.h>

static void		swap_was_lnk(t_read **elem1, t_read **elem2)
{
	int				tmp_was_lnk;

	tmp_was_lnk = (*elem1)->was_lnk;
	(*elem1)->was_lnk = (*elem2)->was_lnk;
	(*elem2)->was_lnk = tmp_was_lnk;
}

static void		swap_elems(t_read *elem1, t_read *elem2)
{
	char			*tmp_name;
	char			*tmp_path;
	struct stat		*tmp_l_stat;
	struct s_read	*tmp_contents;
	struct s_lopt	*tmp_lopt;

	swap_was_lnk(&elem1, &elem2);
	tmp_name = elem1->name;
	tmp_path = elem1->path;
	tmp_l_stat = elem1->l_stat;
	tmp_contents = elem1->contents;
	tmp_lopt = elem1->lopt;
	elem1->name = elem2->name;
	elem1->path = elem2->path;
	elem1->l_stat = elem2->l_stat;
	elem1->contents = elem2->contents;
	elem1->lopt = elem2->lopt;
	elem2->name = tmp_name;
	elem2->path = tmp_path;
	elem2->l_stat = tmp_l_stat;
	elem2->contents = tmp_contents;
	elem2->lopt = tmp_lopt;
}

t_read			*sort_asc(t_read *list)
{
	t_read		*i;
	t_read		*j;

	i = list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (ft_strcmp(i->name, j->name) > 0)
				swap_elems(i, j);
			else
				j = j->next;
		}
		i = i->next;
	}
	return (list);
}

t_read			*sort_by_time(t_read *list)
{
	t_read		*i;
	t_read		*j;

	i = list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if ((i->l_stat->st_mtime) < (j->l_stat->st_mtime) ||
				((i->l_stat->st_mtime) == (j->l_stat->st_mtime) &&
ft_strcmp(i->name, j->name) > 0))
				swap_elems(i, j);
			else
				j = j->next;
		}
		i = i->next;
	}
	return (list);
}

t_read			*sort_by_reverse(t_read *list)
{
	t_read *current;
	t_read *tmp;

	current = list;
	list = NULL;
	while (current)
	{
		tmp = current;
		current = current->next;
		tmp->next = list;
		list = tmp;
	}
	return (list);
}

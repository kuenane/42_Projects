/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:07:29 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/14 10:22:23 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

static t_read	*t_option(t_read *list, int option_t)
{
	t_read	*current;

	if (!option_t)
		return (list);
	list = sort_by_time(list);
	current = list;
	while (current)
	{
		current->contents = sort_by_time(current->contents);
		current = current->next;
	}
	return (list);
}

static t_read	*r_option(t_read *list, int option_r)
{
	t_read	*current;

	if (!option_r)
		return (list);
	list = sort_by_reverse(list);
	current = list;
	while (current)
	{
		current->contents = sort_by_reverse(current->contents);
		current = current->next;
	}
	return (list);
}

static void		l_option_files(t_read *list, int option_l)
{
	size_t	*max;

	max = give_max_files(list);
	while (list)
	{
		if (list->lopt->rights[0] != 'd')
		{
			if (!option_l)
				ft_putendl(list->name);
			else
				print_l_option_file(list, max);
		}
		list = list->next;
	}
}

static void		l_option_dirs(t_read *list, int option_l, int enabled)
{
	while (list)
	{
		if (list->lopt->rights[0] == 'd')
		{
			if (!option_l)
			{
				if_enabled_no_l(list, enabled);
				print_list(list->contents);
			}
			else
			{
				if_enabled_l(list->name, enabled);
				print_l_option_dir(list->contents);
			}
			if (list->next && is_last_dir(list->next) == 0)
				ft_putchar('\n');
		}
		list = list->next;
	}
}

void			apply_options(t_read **list, int *options)
{
	int		enabled;

	enabled = check_if_enabled(*list);
	(*list) = t_option((*list), options[4]);
	(*list) = r_option((*list), options[3]);
	if (options[2])
		(*list) = put_minor_major(*list);
	l_option_files((*list), options[2]);
	if (give_nb_dirs(*list) && give_nb_files(*list))
		ft_putchar('\n');
	l_option_dirs((*list), options[2], enabled);
}

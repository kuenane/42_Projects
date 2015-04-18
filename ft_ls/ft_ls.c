/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 19:11:04 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/14 09:43:45 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

static void		second_function(t_read *current, int *options)
{
	put_contents(current);
	current->contents = a_option(current->contents, options[1]);
	current->contents = sort_asc(current->contents);
	put_path(current->contents, current->name);
	current->contents = put_l_stat_contents(&(current->contents));
	put_lopt(current->contents);
}

int				main(int ac, char **av)
{
	int		options[5];
	t_read	*list;
	t_read	*current;

	if (put_options_tab(av, options))
		return (0);
	if (!(list = give_arg(ac, av)))
		list = new_elem(".");
	list = sort_asc(list);
	list = put_l_stat_list(&list, options[2]);
	current = list;
	while (current)
	{
		if (S_ISDIR(current->l_stat->st_mode))
			second_function(current, options);
		current = current->next;
	}
	put_lopt(list);
	apply_options(&list, options);
	return (0);
}

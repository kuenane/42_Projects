/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:38:05 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 15:22:11 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <sys/stat.h>

static void		put_total_blocks(t_read *list)
{
	int		total;

	total = 0;
	if (list)
	{
		while (list)
		{
			total += list->l_stat->st_blocks;
			list = list->next;
		}
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}

char			*give_name(struct dirent *current, int i)
{
	char	*name;

	name = verified_strnew(current->d_namlen);
	while (i < (current->d_namlen))
	{
		name[i] = current->d_name[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

void			print_l_option_dir(t_read *list)
{
	size_t	*max;

	max = give_max(list);
	put_total_blocks(list);
	while (list)
	{
		putstr_with_one_space(list->lopt->rights);
		ft_putchar(' ');
		putstr_l_opt(list->lopt->links, max[0], 'r');
		putstr_l_opt(list->lopt->usr, max[1], 'l');
		ft_putchar(' ');
		putstr_l_opt(list->lopt->gp, max[2], 'l');
		ft_putchar(' ');
		putstr_l_opt(list->lopt->size, max[3], 'r');
		putstr_with_one_space(list->lopt->time);
		if (list->lopt->linked)
			ft_putendl(list->lopt->linked);
		else
			ft_putendl(list->name);
		list = list->next;
	}
}

void			print_l_option_file(t_read *list, size_t *max)
{
	putstr_with_one_space(list->lopt->rights);
	ft_putchar(' ');
	putstr_l_opt(list->lopt->links, max[0], 'r');
	putstr_l_opt(list->lopt->usr, max[1], 'l');
	ft_putchar(' ');
	putstr_l_opt(list->lopt->gp, max[2], 'l');
	ft_putchar(' ');
	putstr_l_opt(list->lopt->size, max[3], 'r');
	putstr_with_one_space(list->lopt->time);
	if (list->lopt->linked)
		ft_putendl(list->lopt->linked);
	else
		ft_putendl(list->name);
}

void			print_list(t_read *list)
{
	while (list)
	{
		ft_putendl(list->name);
		list = list->next;
	}
}

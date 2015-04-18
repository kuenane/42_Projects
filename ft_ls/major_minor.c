/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major_minor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 15:56:38 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 14:35:52 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <stdlib.h>
#include <sys/stat.h>

static char		*give_str_maj_min(t_read *list)
{
	char	*str;
	int		major;
	int		minor;

	major = MAJOR(list->l_stat->st_rdev);
	minor = MINOR(list->l_stat->st_rdev);
	str = ft_strjoin(" ", ft_itoa(major));
	if (minor >= 0 && minor <= 9)
		str = ft_strjoin_free(str, ",   ");
	else if (minor >= 10 && minor <= 99)
		str = ft_strjoin_free(str, ",  ");
	else if (minor >= 100 && minor <= 999)
		str = ft_strjoin_free(str, ", ");
	str = ft_strjoin_free(str, ft_itoa(minor));
	return (str);
}

static int		is_major_minor(char c)
{
	if (c == 'c' || c == 'b')
		return (1);
	return (0);
}

static t_read	*put_it_on_current(t_read *list)
{
	t_read		*current;

	current = list;
	while (current)
	{
		if (is_major_minor(current->lopt->rights[0]))
		{
			free(current->lopt->size);
			current->lopt->size = give_str_maj_min(current);
		}
		current = current->next;
	}
	return (list);
}

t_read			*put_minor_major(t_read *list)
{
	t_read		*current;

	current = put_it_on_current(list);
	while (current)
	{
		current->contents = put_it_on_current(current->contents);
		current = current->next;
	}
	return (list);
}

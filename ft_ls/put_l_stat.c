/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_l_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:01:48 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/14 09:45:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

void			put_error(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

static t_read	*check_if_lnk(t_read *current, int l_option)
{
	struct stat *l_stat;

	if (S_ISLNK(current->l_stat->st_mode) && !l_option)
	{
		current->name = ft_strjoin(current->name, "/");
		current->was_lnk = 1;
		free(current->l_stat);
		l_stat = (struct stat*)verified_malloc(sizeof(struct stat) * 1);
		errno = 0;
		if (!(current->path))
			lstat(current->name, l_stat);
		else
			lstat(current->path, l_stat);
		current->l_stat = l_stat;
	}
	return (current);
}

t_read			*put_l_stat_list(t_read **list, int l_option)
{
	t_read		*current;
	struct stat	*l_stat;
	int			ret;

	current = *list;
	while (current)
	{
		l_stat = (struct stat*)verified_malloc(sizeof(struct stat) * 1);
		errno = 0;
		if (!(current->path))
			ret = lstat(current->name, l_stat);
		else
			ret = lstat(current->path, l_stat);
		if (ret == -1)
		{
			put_error(current->name);
			free(l_stat);
			remove_elem(list, current->name);
		}
		current->l_stat = l_stat;
		current = check_if_lnk(current, l_option);
		current = current->next;
	}
	return (*list);
}

t_read			*put_l_stat_contents(t_read **list)
{
	t_read		*current;
	struct stat	*l_stat;
	int			ret;

	current = *list;
	while (current)
	{
		l_stat = (struct stat*)verified_malloc(sizeof(struct stat) * 1);
		errno = 0;
		if (!(current->path))
			ret = lstat(current->name, l_stat);
		else
			ret = lstat(current->path, l_stat);
		if (ret == -1)
		{
			put_error(current->name);
			free(l_stat);
			remove_elem(list, current->name);
		}
		else
			current->l_stat = l_stat;
		current = current->next;
	}
	return (*list);
}

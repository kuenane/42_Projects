/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_contents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:02:56 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/14 10:35:24 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <stdlib.h>
#include <errno.h>

void			put_path(t_read *list, char *path)
{
	char	*tmp;
	char	*tmp_name;
	size_t	len;

	len = ft_strlen(path);
	while (list)
	{
		free(list->path);
		if (path[len - 1] != '/')
		{
			tmp = verified_strnew(len + 1);
			ft_strcpy(tmp, path);
			tmp[len] = '/';
		}
		else
			tmp = verified_strdup(path);
		tmp_name = verified_strjoin(tmp, list->name);
		list->path = tmp_name;
		list = list->next;
	}
}

void			put_contents(t_read *list)
{
	DIR				*dirp;
	struct dirent	*s_dirent;

	if (!list)
		return ;
	list->contents = NULL;
	errno = 0;
	s_dirent = (struct dirent*)verified_malloc(sizeof(struct dirent) * 1);
	if (!(dirp = opendir(list->name)))
		put_error(list->name);
	else
	{
		while ((s_dirent = readdir(dirp)))
			list->contents = add_elem(list->contents, give_name(s_dirent, 0));
		closedir(dirp);
		free(s_dirent);
	}
}

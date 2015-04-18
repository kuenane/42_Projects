/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:34:01 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/14 09:19:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <sys/stat.h>

static char		give_type(t_read *list)
{
	if (S_ISBLK(list->l_stat->st_mode))
		return ('b');
	if (S_ISCHR(list->l_stat->st_mode))
		return ('c');
	if (S_ISDIR(list->l_stat->st_mode))
		return ('d');
	if (S_ISLNK(list->l_stat->st_mode))
		return ('l');
	if (S_ISSOCK(list->l_stat->st_mode))
		return ('s');
	if (S_ISFIFO(list->l_stat->st_mode))
		return ('p');
	return ('-');
}

static char		check_suid(t_read *list)
{
	if (ST_MODE(S_IXUSR))
	{
		if (ST_MODE(S_ISUID))
			return ('s');
		return ('x');
	}
	if (ST_MODE(S_ISUID))
		return ('S');
	return ('-');
}

static char		check_guid(t_read *list)
{
	if (ST_MODE(S_IXGRP))
	{
		if (ST_MODE(S_ISGID))
			return ('s');
		return ('x');
	}
	if (ST_MODE(S_ISGID))
		return ('S');
	return ('-');
}

static char		check_sticky(t_read *list)
{
	if (ST_MODE(S_IXOTH))
	{
		if (ST_MODE(S_ISVTX))
			return ('t');
		return ('x');
	}
	if (ST_MODE(S_ISVTX))
		return ('T');
	return ('-');
}

char			*give_type_and_rights(t_read *list)
{
	char	*rights;

	rights = verified_strnew(10);
	rights[0] = give_type(list);
	rights[1] = ST_MODE(S_IRUSR) ? 'r' : '-';
	rights[2] = ST_MODE(S_IWUSR) ? 'w' : '-';
	rights[3] = check_suid(list);
	rights[4] = ST_MODE(S_IRGRP) ? 'r' : '-';
	rights[5] = ST_MODE(S_IWGRP) ? 'w' : '-';
	rights[6] = check_guid(list);
	rights[7] = ST_MODE(S_IROTH) ? 'r' : '-';
	rights[8] = ST_MODE(S_IWOTH) ? 'w' : '-';
	rights[9] = check_sticky(list);
	rights[10] = '\0';
	return (rights);
}

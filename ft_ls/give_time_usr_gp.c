/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_time_usr_gp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 09:47:56 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 16:31:10 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

static char		*more_than_6months(time_t arg_time)
{
	char			*str_time;
	char			*tmp;
	size_t			len;

	str_time = verified_strdup(ctime(&arg_time));
	tmp = (verified_strdup(str_time));
	str_time = (ft_strsub_free(str_time, 4, 6));
	len = ft_strlen(tmp);
	tmp = ft_strsub_free(tmp, len - 5, len);
	str_time = ft_strjoin_free(str_time, "  ");
	str_time = ft_strjoin_free(str_time, tmp);
	len = 0;
	while (str_time[len] && str_time[len] != '\n')
		len++;
	if (str_time && str_time[len] == '\n')
		str_time[len] = '\0';
	return (str_time);
}

char			*give_str_time(t_read *list)
{
	char			*str_time;
	time_t			arg_time;
	time_t			now;

	if (list)
	{
		time(&now);
		arg_time = list->l_stat->st_mtime;
		if (((now - arg_time) <= (time_t)15552000) && (now >= arg_time))
		{
			str_time = verified_strdup(ctime(&arg_time));
			if ((str_time = ft_strsub_free(str_time, 4, 12)))
				return (str_time);
		}
		else
			return (more_than_6months(arg_time));
	}
	return (NULL);
}

char			*give_linked(char *name, char *path)
{
	char			*tmp;
	char			*linked;
	size_t			len;

	linked = verified_strnew(1024);
	if (path)
		len = readlink(path, linked, 1024);
	else
		len = readlink(name, linked, 1024);
	if (len <= 0)
		return (NULL);
	linked[len] = '\0';
	tmp = verified_strjoin(" -> ", linked);
	free(linked);
	linked = verified_strjoin(name, tmp);
	free(tmp);
	return (linked);
}

char			*give_usr(t_read *list)
{
	struct passwd		*usr;

	if (list)
	{
		usr = (struct passwd*)verified_malloc(sizeof(struct passwd) * 1);
		if ((usr = getpwuid(list->l_stat->st_uid)))
			return (verified_strdup(usr->pw_name));
		free(usr);
	}
	return (verified_strdup(ft_itoa(list->l_stat->st_uid)));
}

char			*give_gp(t_read *list)
{
	struct group		*gp;

	if (list)
	{
		gp = (struct group*)verified_malloc(sizeof(struct group) * 1);
		if ((gp = getgrgid(list->l_stat->st_gid)) != NULL)
			return (verified_strdup(gp->gr_name));
		free(gp);
	}
	return (verified_strdup(ft_itoa(list->l_stat->st_gid)));
}

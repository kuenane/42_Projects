/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_tab_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 07:16:06 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 15:44:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static char		*give_str_line(char *file_name, int fd)
{
	char	*line;

	errno_open_read_close(file_name);
	if ((get_next_line(fd, &line) == -1))
		return (NULL);
	errno_open_read_close(file_name);
	return (line);
}

static int		give_nb_int(char *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s < '0' || *s > '9')
		{
			if (!*s)
				return (i);
			s++;
		}
		if (*s >= '0' && *s <= '9')
			i++;
		while (*s >= '0' && *s <= '9')
		{
			if (!*s)
				return (i);
			s++;
		}
	}
	return (i);
}

static t_pt		*give_int_line(char *file_name, int fd)
{
	char	*c_line;
	t_pt	*i_line;
	int		nb_int;
	int		i;
	int		pos;

	c_line = give_str_line(file_name, fd);
	nb_int = give_nb_int(c_line);
	i_line = (t_pt*)verified_malloc(sizeof(t_pt) * (nb_int + 1));
	i = 0;
	while (i < nb_int)
	{
		pos = pos_first_digit(c_line);
		i_line[i].z = ft_getnbr(c_line, pos);
		i_line[i].z = -(i_line[i].z);
		pos = pos_after_digit(c_line, pos);
		c_line = verified_strsub_free(c_line, pos);
		i++;
	}
	free(c_line);
	i_line[i].z = EOL;
	return (i_line);
}

t_pt			**give_tab_map(char *file_name, int nb_line)
{
	int		fd;
	t_pt	**tab;
	int		i;

	fd = open(file_name, O_RDONLY);
	tab = (t_pt**)verified_malloc(sizeof(t_pt*) * (nb_line + 1));
	i = 0;
	while (i < nb_line)
	{
		tab[i] = give_int_line(file_name, fd);
		i++;
	}
	tab[nb_line] = (t_pt*)verified_malloc(sizeof(t_pt) * 1);
	tab[nb_line] = NULL;
	tab = apply_iso_projection(tab);
	close(fd);
	return (tab);
}

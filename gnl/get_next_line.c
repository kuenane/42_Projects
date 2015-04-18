/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 09:03:46 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/19 14:20:14 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**CAUTION : define on "EOF", "BUFF_SIZE", "GI" and "GBUF"
*/

#include "get_next_line.h"

static int		ft_verify(int fd, int *fd_save, char **line)
{
	if (line == NULL)
		return (-1);
	if (fd < 0)
		return (-1);
	if (*fd_save == -100)
		*fd_save = fd;
	*line = ft_memalloc(1);
	if ((*line == NULL) || (*fd_save != fd))
		return (-1);
	return (1);
}

static void		ft_return_index(char *buf, int *i)
{
	while (buf[*i] && buf[*i] != EOF)
	{
		if (buf[*i] == '\n')
			return ;
		*i = *i + 1;
	}
	*i = -1;
}

static int		ft_alloc_fresh_line(t_gnl_list *gnl, char **line, int gi_zero)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*line));
	ft_strcpy(tmp, *line);
	if (tmp == NULL)
		return (-1);
	free(*line);
	if (gi_zero)
		*line = ft_strjoin(tmp, GBUF);
	else
		*line = ft_strjoin(tmp, ft_strsub(GBUF, 0, GI));
	if (*line == NULL)
		return (-1);
	free(tmp);
	return (0);
}

static int		ft_gnl(t_gnl_list *gnl, char **line)
{
	GI = 0;
	ft_return_index(GBUF, &(GI));
	if (GI >= 0)
	{
		if (GI == 0)
		{
			ft_strcpy(GBUF, ft_strsub(GBUF, GI + 1, ft_strlen(GBUF)));
			if (GBUF == NULL)
				return (-1);
			return (1);
		}
		if ((ft_alloc_fresh_line(gnl, line, 0)) == -1)
			return (-1);
		ft_strcpy(GBUF, ft_strsub(GBUF, GI + 1, ft_strlen(GBUF)));
		if (GBUF == NULL)
			return (-1);
		return (1);
	}
	if ((ft_alloc_fresh_line(gnl, line, 1)) == -1)
		return (-1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl_list	gnl = {"", -100, 0};
	int					ret;
	int					ret_ft_gnl;

	if (ft_verify(fd, &(gnl.fd_save), &(*line)) == -1)
		return (-1);
	if (gnl.buf[0])
		if ((ret_ft_gnl = ft_gnl(&(gnl), line)))
			return (ret_ft_gnl);
	while ((ret = read(fd, gnl.buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		gnl.buf[ret] = '\0';
		if ((ret_ft_gnl = ft_gnl(&(gnl), line)))
			return (ret_ft_gnl);
	}
	if (ft_strlen(*line) == 0)
		return (0);
	return (1);
}

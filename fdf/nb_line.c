/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:50:30 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/17 16:02:21 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static int		check_for_backn(int ret, char *buf)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (i != ret)
	{
		if (buf[i] == '\n')
			nb++;
		i++;
	}
	if (buf[i - 1] != '\n')
		nb++;
	return (nb);
}

int				nb_line(char *file_name)
{
	char	buf[65];
	int		fd;
	int		nb;
	int		ret;

	init_errno();
	nb = 0;
	fd = open(file_name, O_RDONLY);
	errno_open_read_close(file_name);
	while ((ret = read(fd, &buf, 64)))
	{
		errno_open_read_close(file_name);
		nb += check_for_backn(ret, buf);
	}
	close(fd);
	errno_open_read_close(file_name);
	return (nb);
}

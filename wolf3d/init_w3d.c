/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_w3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 14:46:51 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 10:37:32 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static void		init_mlx(t_w3d *w3d)
{
	if (!(w3d->mlx = mlx_init()))
		ft_exit("Error: cannot init mlx");
	if (!(w3d->win = mlx_new_window(w3d->mlx, WIDTH, HEIGHT, "Wolf3d")))
		ft_exit("Error: cannot load mlx window");
	if (!(w3d->img = mlx_new_image(w3d->mlx, WIDTH, HEIGHT)))
		ft_exit("Error: cannot load mlx image");
	w3d->data = mlx_get_data_addr(w3d->img, &(w3d->octpp), &(w3d->size_line),
								&(w3d->endian));
	w3d->octpp /= 8;
}

static void		errno_open_read_close(char *file_name)
{
	if (!errno)
		return ;
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ", 2);
	ft_exit(strerror(errno));
}

static int		*give_intline(char *line, int wmap)
{
	int		*intline;
	int		i;

	if ((int)ft_strlen(line) != wmap)
		ft_exit("Invalid map.");
	intline = v_malloc(sizeof(int) * wmap);
	i = -1;
	while (++i < wmap)
	{
		if (!ft_isdigit(line[i]))
			ft_exit("Invalid map.");
		intline[i] = line[i] - '0';
	}
	return (intline);
}

int				**import_map(int *hmap, int *wmap, int fd)
{
	int		**tab;
	char	*line;
	int		ret;
	int		i;

	if (get_next_line(fd, &line) != 1 || !ft_str_isint(line)
		|| (*hmap = ft_atoi(line)) <= 0)
		ft_exit("Invalid map.");
	v_free(line);
	tab = (int**)v_malloc(sizeof(int*) * *hmap);
	*wmap = -42;
	i = 0;
	while ((ret = get_next_line(fd, &line)) && i < *hmap)
	{
		if (ret == -1)
			ft_exit("Invalid map.");
		if (*wmap == -42)
			*wmap = ft_strlen(line);
		tab[i] = give_intline(line, *wmap);
		v_free(line);
		i++;
	}
	if (ret || i != *hmap)
		ft_exit("Invalid map.");
	return (v_free(line), tab);
}

void			init_w3d(t_w3d *w3d, char *av1)
{
	int		fd;

	errno = 0;
	fd = open(av1, O_RDONLY);
	errno_open_read_close(av1);
	w3d->map = import_map(&w3d->hmap, &w3d->wmap, fd);
	close(fd);
	errno_open_read_close(av1);
	init_player_pos(w3d);
	init_mlx(w3d);
	load_weapon(w3d);
	w3d->sky = init_sky();
	w3d->start = 1;
	w3d->mapstate = 1;
	w3d->pause = 0;
	w3d->sky_clk = 0;
}

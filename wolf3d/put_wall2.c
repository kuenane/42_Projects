/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 09:53:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 20:10:14 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <math.h>

static int		is_a_wall(t_w3d *w3d, double ref_x, double ref_y)
{
	int		x;
	int		y;

	x = (int)floor(ref_x / 64.0);
	y = (int)floor(ref_y / 64.0);
	if (x < 0 || x >= w3d->wmap || y < 0 || y >= w3d->hmap || w3d->map[y][x])
		return (1);
	return (0);
}

static double	set_color(t_w3d *w3d, double ret1, double ret2, double cur_ray)
{
	if (ret1 < ret2)
	{
		if (cur_ray < 180 && cur_ray > 0)
			return (w3d->cur_color = 0x00CCFF, ret1);
		return (w3d->cur_color = 0x00A3CC, ret1);
	}
	if (cur_ray < 270 && cur_ray > 90)
		return (w3d->cur_color = 0x008FB2, ret2);
	return (w3d->cur_color = 0x00B8E6, ret2);
}

static void		go_to_next_point(double *ax, double xa, double *ay, double ya)
{
	*ax += xa;
	*ay += ya;
}

double			give_littlest(t_w3d *w3d, double ay, double bx, double cur_ray)
{
	double ax;
	double by;
	double xa;
	double ya;

	ya = 64.0;
	if (cur_ray > 0 && cur_ray < 180)
		ya *= -1;
	ax = (w3d->posx + (w3d->posy - ay) / tan(cur_ray * M_PI / 180));
	xa = -ya / tan(cur_ray * M_PI / 180);
	while (!is_a_wall(w3d, ax, ay))
		go_to_next_point(&ax, xa, &ay, ya);
	xa = 64.0;
	if (cur_ray > 90 && cur_ray < 270)
		xa *= -1;
	by = w3d->posy + (w3d->posx - bx) * tan(cur_ray * M_PI / 180);
	ya = -xa * tan(cur_ray * M_PI / 180);
	while (!is_a_wall(w3d, bx, by))
		go_to_next_point(&bx, xa, &by, ya);
	ax = sqrt(pow((w3d->posx - ax), 2) + pow((w3d->posy - ay), 2));
	bx = sqrt(pow((w3d->posx - bx), 2) + pow((w3d->posy - by), 2));
	return (set_color(w3d, ax, bx, cur_ray));
}

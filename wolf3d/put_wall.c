/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 09:53:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 10:52:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <math.h>

static double	calc_horiz(t_w3d *w3d, double cur_ray)
{
	double	ay;

	if (cur_ray > 0 && cur_ray < 180)
		ay = floor(w3d->posy / 64.0) * (64.0) - 0.01;
	else
		ay = floor(w3d->posy / 64.0) * (64.0) + 64.0;
	return (ay);
}

static double	calc_verti(t_w3d *w3d, double cur_ray)
{
	double	bx;

	if (cur_ray > 90 && cur_ray < 270)
		bx = floor(w3d->posx / 64.0) * (64.0) - 0.01;
	else
		bx = floor(w3d->posx / 64.0) * (64.0) + 64.0;
	return (bx);
}

static double	launch_ray(t_w3d *w3d, double cur_ray)
{
	double	ay;
	double	bx;
	double	raylen;

	ay = calc_horiz(w3d, cur_ray);
	bx = calc_verti(w3d, cur_ray);
	raylen = give_littlest(w3d, ay, bx, cur_ray);
	raylen = raylen * cos(ft_rad(cur_ray - w3d->ang)) * 0.050;
	return (raylen);
}

static void		draw_ray(t_w3d *w3d, int raylen, int i)
{
	int		c;

	c = HEIGHT;
	while (c > 0)
	{
		if (c > HEIGHT / 2 - (raylen / 2) && c < (raylen / 2) + HEIGHT / 2)
			put_pixel_to_img(w3d, i, -(c - HEIGHT), w3d->cur_color);
		c--;
	}
}

void			put_walls(t_w3d *w3d)
{
	int		i;
	double	cur_ray;
	double	raylen;

	i = -1;
	cur_ray = w3d->ang + HALF_FOV;
	while (++i < WIDTH)
	{
		raylen = 64 / launch_ray(w3d, cur_ray) * 22;
		draw_ray(w3d, (int)raylen, i);
		cur_ray -= ANGLE_BET_RAY;
		if (cur_ray < 0)
			cur_ray += 360;
		else if (cur_ray > 360)
			cur_ray -= 360;
	}
}

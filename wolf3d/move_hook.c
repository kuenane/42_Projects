/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 08:11:13 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 08:56:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <math.h>

#define POSX w3d->posx
#define POSY w3d->posy
#define DIRX w3d->dirx
#define DIRY w3d->diry
#define WMAP w3d->map

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

void			left_key_pressed(t_w3d *w3d)
{
	move_sky_l_key(w3d);
	if ((w3d->ang += ROT_SPEED) > 360)
		w3d->ang -= 360;
}

void			right_key_pressed(t_w3d *w3d)
{
	move_sky_r_key(w3d);
	if ((w3d->ang -= ROT_SPEED) < 0)
		w3d->ang += 360;
}

void			up_key_pressed(t_w3d *w3d)
{
	int		newx;
	int		newy;

	newy = w3d->posy - MV_SPEED * sin(ft_rad(w3d->ang));
	newx = w3d->posx + MV_SPEED * cos(ft_rad(w3d->ang));
	if (is_a_wall(w3d, newx, newy))
		return ;
	w3d->posy = newy;
	w3d->posx = newx;
}

void			down_key_pressed(t_w3d *w3d)
{
	int		newx;
	int		newy;

	newy = w3d->posy + MV_SPEED * sin(ft_rad(w3d->ang));
	newx = w3d->posx - MV_SPEED * cos(ft_rad(w3d->ang));
	if (is_a_wall(w3d, newx, newy))
		return ;
	w3d->posy = newy;
	w3d->posx = newx;
}

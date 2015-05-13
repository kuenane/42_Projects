/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_expose_and_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 09:40:51 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/13 06:55:20 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <mlx.h>

#define MENU_IMG w3d->menu_img

int		manage_expose_hook(void *param)
{
	t_w3d	*w3d;

	w3d = (t_w3d*)param;
	ft_bzero(w3d->data, WIDTH * HEIGHT * w3d->octpp);
	if (w3d->start)
		return (mlx_put_image_to_window(w3d->mlx, w3d->win, MENU_IMG, 0, 0), 1);
	put_sky_and_floor(w3d);
	if (w3d->pause)
	{
		mlx_put_image_to_window(w3d->mlx, w3d->win, w3d->img, 0, 0);
		mlx_put_image_to_window(w3d->mlx, w3d->win, w3d->pause_img, 0, 0);
	}
	else
	{
		put_walls(w3d);
		if (w3d->mapstate)
			put_minimap(w3d);
		mlx_put_image_to_window(w3d->mlx, w3d->win, w3d->img, 0, 0);
		put_weapon(w3d);
		mlx_put_image_to_window(w3d->mlx, w3d->win, w3d->game_img, 0, 0);
	}
	return (1);
}

int		key_pressed(int keycode, t_w3d *w3d)
{
	if (keycode == ESC_KEY)
		ft_exit("exit...");
	if ((w3d->start && keycode != RET_KEY) || (w3d->pause && keycode != P_KEY))
		return (1);
	if (keycode == RET_KEY)
		w3d->start = 0;
	else if (keycode == P_KEY)
		w3d->pause = (w3d->pause) ? 0 : 1;
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		left_key_pressed(w3d);
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		right_key_pressed(w3d);
	else if (keycode == UP_KEY || keycode == W_KEY)
		up_key_pressed(w3d);
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		down_key_pressed(w3d);
	else if (keycode == Q_KEY)
		manage_weapon_hook(w3d);
	else if (keycode == SP_KEY)
		enable_shoot(w3d);
	else if (keycode == E_KEY)
		w3d->mapstate = (w3d->mapstate) ? 0 : 1;
	manage_expose_hook(w3d);
	return (1);
}

void	set_expose_and_key(t_w3d *w3d)
{
	mlx_expose_hook(w3d->win, &manage_expose_hook, w3d);
	mlx_hook(w3d->win, 2, 1, &key_pressed, w3d);
	mlx_loop_hook(w3d->mlx, &manage_loop_hook, w3d);
	mlx_loop(w3d->mlx);
}

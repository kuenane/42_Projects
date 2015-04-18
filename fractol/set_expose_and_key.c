/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_expose_and_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:32:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:11:39 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

int		manage_expose_hook(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (CHOICE == '1')
		mandelbrot(mlx);
	if (CHOICE == '2')
		julia(mlx);
	if (CHOICE == '3')
		douady_rabbit(mlx);
	if (CHOICE == '4')
		noun(mlx);
	if (CHOICE == '5')
		chromosom(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

int		manage_key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	if (keycode == 65307)
		exit(0);
	mlx = (t_mlx*)param;
	if (keycode == 99)
	{
		if (WHICHCOL == 8)
			WHICHCOL = 0;
		else
			WHICHCOL++;
		REDO = 1;
	}
	return (1);
}

int		manage_loop_hook(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (REDO)
	{
		manage_expose_hook(mlx);
		REDO = 0;
	}
	return (1);
}

void	set_expose_and_key(t_mlx *mlx)
{
	mlx_expose_hook(mlx->win, &manage_expose_hook, mlx);
	mlx_key_hook(mlx->win, &manage_key_hook, mlx);
	mlx_loop_hook(mlx->mlx, &manage_loop_hook, mlx);
	mlx_hook(mlx->win, 4, 1 << 2, &manage_mouse_scroll_hook, mlx);
	mlx_hook(mlx->win, 6, 1 << 6, &manage_mouse_move_hook, mlx);
}

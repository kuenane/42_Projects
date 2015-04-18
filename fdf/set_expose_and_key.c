/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_expose_and_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 09:54:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 18:12:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

int		manage_expose_hook(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	mlx_string_put(mlx->mlx, mlx->win, 1000, 500, MLX_COLOR, "Loading map...");
	ft_bzero(mlx->data, WIDTH * HEIGHT * mlx->octpp);
	put_map(mlx, mlx->tab);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

int		manage_key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (keycode == 65307)
		exit(0);
	if (keycode >= 65361 && keycode <= 65364)
	{
		mlx->tab = hook_move_map(mlx->tab, keycode);
		manage_expose_hook(mlx);
	}
	return (1);
}

void	set_expose_and_key(t_mlx *mlx)
{
	mlx_expose_hook(mlx->win, &manage_expose_hook, mlx);
	mlx_key_hook(mlx->win, &manage_key_hook, mlx);
}

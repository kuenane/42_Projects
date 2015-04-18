/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 16:26:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/25 18:22:28 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_loop(LG_DB zm)
{
	int		i;

	i = 0;
	while ((zm /= 1.3) > 1)
		i++;
	return (i * 5 + 30);
}

int			manage_mouse_scroll_hook(int button, int x, int y, void *param)
{
	t_mlx	*mlx;
	t_coord	new;
	t_ri	old_zm;

	mlx = (t_mlx*)param;
	if (button == 4 || (button == 5 && mlx->zoom > 100))
	{
		new.x = CURX + x;
		new.y = CURY + y;
		old_zm.r = new.x / ZOOM;
		old_zm.i = new.y / ZOOM;
		ZOOM *= (button == 4) ? 1.05 : 0.95;
		CURX += (old_zm.r - (new.x / ZOOM)) * ZOOM;
		CURY += (old_zm.i - (new.y / ZOOM)) * ZOOM;
		ITER = get_loop(ZOOM);
		REDO = 1;
	}
	return (1);
}

int			manage_mouse_move_hook(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (CHOICE == '2')
		REDO = 1;
	MSX = (long)x;
	MSY = (long)y;
	return (1);
}

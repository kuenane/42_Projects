/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 21:14:15 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 08:23:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <libft.h>

static void		init_julia(t_mlx *mlx, t_coord c, int *i)
{
	CR = (CURX - (MSX - WIDTH)) / ZOOM;
	CI = (CURY - (MSY - HEIGHT)) / ZOOM;
	ZR = c.x / ZOOM;
	ZI = c.y / ZOOM;
	SQZR = ZR * ZR;
	SQZI = ZI * ZI;
	*i = ITER;
}

void			julia(t_mlx *mlx)
{
	t_coord		c;
	t_coord		tmp;
	int			i;

	tmp.x = WIDTH + CURX;
	tmp.y = HEIGHT + CURY;
	c = mlx->current;
	while (++c.y < tmp.y)
	{
		c.x = CURX;
		while (++c.x < tmp.x)
		{
			init_julia(mlx, c, &i);
			while ((SQZR + SQZI) < 8 && --i > 0)
			{
				SQZR = ZR * ZR;
				SQZI = ZI * ZI;
				ZI = 2 * ZI * ZR + CI;
				ZR = SQZR - SQZI + CR;
			}
			put_current_pixel(mlx, c, i);
		}
	}
}

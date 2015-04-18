/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:22:36 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 08:24:13 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <libft.h>

static void		init_mandelbrot(t_mlx *mlx, t_coord c, int *i)
{
	CR = c.x / ZOOM;
	CI = c.y / ZOOM;
	ZR = 0;
	ZI = 0;
	SQZR = 0;
	SQZI = 0;
	*i = ITER;
}

void			mandelbrot(t_mlx *mlx)
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
			init_mandelbrot(mlx, c, &i);
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

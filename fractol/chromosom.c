/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chromosom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:48:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 14:48:44 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <libft.h>

static void		init_chromosom(t_mlx *mlx, t_coord c, int *i)
{
	CR = 0.02;
	CI = 1;
	ZR = c.y / ZOOM;
	ZI = c.x / ZOOM;
	SQZR = ZR * ZR;
	SQZI = ZI * ZI;
	*i = ITER;
	(void)c;
}

void			chromosom(t_mlx *mlx)
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
			init_chromosom(mlx, c, &i);
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

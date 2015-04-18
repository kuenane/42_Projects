/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noun.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:57:41 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:00:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <libft.h>

static void		init_noun(t_mlx *mlx, t_coord c, int *i)
{
	CR = -0.846545;
	CI = -0.2558;
	ZR = c.x / ZOOM;
	ZI = c.y / ZOOM;
	SQZR = ZR * ZR;
	SQZI = ZI * ZI;
	*i = ITER;
}

void			noun(t_mlx *mlx)
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
			init_noun(mlx, c, &i);
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

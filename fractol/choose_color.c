/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 18:31:33 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 08:49:21 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <libft.h>

#define FULLBLACK 0x000000
#define BLUEBLACK (ITER - i) * 255 / (ITER)
#define TEST ITER * 255 / ITER + i

static void		col0(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 300 / ITER;
	if (i < 100)
		color = i * 25;
	else if (i < 200)
		color = (i - 100) * 25;
	else if (i < 300)
		color = (i - 200) * 25;
	else if (i < 400)
		color = 255 - ((i - 300) * 25);
	else if (i < 500)
		color = (i - 400) * 25;
	else
		color = 255 - ((i - 500) * 25);
	put_pixel_to_img(mlx, c.x - CURX, c.y - CURY, color);
}

static void		col1(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 1500 / ITER;
	if (i < 100)
		color = i * 25;
	else if (i < 200)
		color = (i - 100) * 25;
	else if (i < 300)
		color = (i - 200) * 25;
	else if (i < 400)
		color = 255 - ((i - 300) * 25);
	else if (i < 500)
		color = (i - 400) * 25;
	else
		color = 255 - ((i - 500) * 25);
	put_pixel_to_img(mlx, c.x - CURX, c.y - CURY, color);
}

static void		col2(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 2600 / ITER;
	if (i < 100)
		color = i * 25;
	else if (i < 200)
		color = (i - 100) * 25;
	else if (i < 300)
		color = (i - 200) * 25;
	else if (i < 400)
		color = 255 - ((i - 300) * 25);
	else if (i < 500)
		color = (i - 400) * 25;
	else
		color = 255 - ((i - 500) * 25);
	put_pixel_to_img(mlx, c.x - CURX, c.y - CURY, color);
}

static void		col3(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 800 / ITER;
	if (i < 100)
		color = i * 25;
	else if (i < 200)
		color = (i - 100) * 25;
	else if (i < 300)
		color = (i - 200) * 25;
	else if (i < 400)
		color = 255 - ((i - 300) * 25);
	else if (i < 500)
		color = (i - 400) * 25;
	else
		color = 255 - ((i - 500) * 25);
	put_pixel_to_img(mlx, c.x - CURX, c.y - CURY, color);
}

void			put_current_pixel(t_mlx *mlx, t_coord c, int i)
{
	if (!i)
		put_pixel_to_img(mlx, c.x - CURX, c.y - CURY, FULLBLACK);
	else
	{
		if (WHICHCOL == 0)
			col0(mlx, c, i);
		else if (WHICHCOL == 1)
			col1(mlx, c, i);
		else if (WHICHCOL == 2)
			col2(mlx, c, i);
		else if (WHICHCOL == 3)
			col3(mlx, c, i);
		else if (WHICHCOL == 4)
			col4(mlx, c, i);
		else if (WHICHCOL == 5)
			col5(mlx, c, i);
		else if (WHICHCOL == 6)
			col6(mlx, c, i);
		else if (WHICHCOL == 7)
			col7(mlx, c, i);
		else
			col8(mlx, c, i);
	}
}

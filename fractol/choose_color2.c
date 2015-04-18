/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 08:38:22 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 08:48:58 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <libft.h>

#define FULLBLACK 0x000000

void	col4(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 3300 / ITER;
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

void	col5(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 40000 / ITER;
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

void	col6(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 150000 / ITER;
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

void	col7(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 520 / ITER;
	if (i < 100)
		color = i * 50;
	else if (i < 200)
		color = (i - 100) * 50;
	else if (i < 300)
		color = (i - 200) * 50;
	else if (i < 400)
		color = 255 - ((i - 300) * 50);
	else if (i < 500)
		color = (i - 400) * 50;
	else
		color = 255 - ((i - 500) * 50);
	put_pixel_to_img(mlx, c.x - CURX, c.y - CURY, color);
}

void	col8(t_mlx *mlx, t_coord c, int i)
{
	int		color;

	i = i * 70000 / ITER;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:02:50 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 20:24:48 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <mlx.h>

#define TOP (HEIGHT - w3d->hmap * MMAP - 10)
#define LFT 10
#define MCOLOR 0xFFFFFF
#define PCOLOR 0xB3C628
#define POSX w3d->posx
#define POSY w3d->posy

static void		draw_rect(t_w3d *w3d, int xsrc, int ysrc, int color)
{
	int		x;
	int		y;
	int		xdst;
	int		ydst;

	xdst = xsrc + MMAP;
	ydst = ysrc + MMAP;
	y = ysrc;
	while (y < ydst)
	{
		x = xsrc;
		while (x < xdst)
		{
			put_pixel_to_img(w3d, x, y, color);
			x++;
		}
		y++;
	}
}

void			put_minimap(t_w3d *w3d)
{
	int		i;
	int		j;

	i = -1;
	while (++i < w3d->hmap)
	{
		j = -1;
		while (++j < w3d->wmap)
			if (w3d->map[i][j])
				draw_rect(w3d, j * MMAP + LFT, i * MMAP + TOP, MCOLOR);
	}
	draw_rect(w3d, POSX * MMAP / 64 + LFT, POSY * MMAP / 64 + TOP, PCOLOR);
}

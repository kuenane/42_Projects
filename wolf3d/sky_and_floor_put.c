/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:37:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/08 17:38:21 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

static void		put_moon_detail(t_w3d *w3d, t_pt *pt)
{
	ft_draw_line_grey(w3d, pt->x + 8, pt->x + 12, pt->y + 2);
	ft_draw_line_grey(w3d, pt->x + 5, pt->x + 19, pt->y + 3);
	ft_draw_line_grey(w3d, pt->x + 5, pt->x + 17, pt->y + 4);
	ft_draw_line_grey(w3d, pt->x + 6, pt->x + 15, pt->y + 5);
	ft_draw_line_grey(w3d, pt->x + 12, pt->x + 18, pt->y + 6);
	ft_draw_line_grey(w3d, pt->x + 26, pt->x + 30, pt->y + 6);
	ft_draw_line_grey(w3d, pt->x + 23, pt->x + 33, pt->y + 7);
	ft_draw_line_grey(w3d, pt->x + 23, pt->x + 29, pt->y + 8);
	ft_draw_line_grey(w3d, pt->x + 24, pt->x + 31, pt->y + 9);
	ft_draw_line_grey(w3d, pt->x + 15, pt->x + 17, pt->y + 12);
	ft_draw_line_grey(w3d, pt->x + 15, pt->x + 25, pt->y + 13);
	ft_draw_line_grey(w3d, pt->x + 17, pt->x + 25, pt->y + 13);
	ft_draw_line_grey(w3d, pt->x + 18, pt->x + 23, pt->y + 14);
	ft_draw_line_grey(w3d, pt->x + 14, pt->x + 21, pt->y + 15);
}

static void		put_moon(t_w3d *w3d, t_pt *pt)
{
	ft_draw_line_white(w3d, pt->x + 0, pt->x + 40, pt->y);
	ft_draw_line_white(w3d, pt->x + 0, pt->x + 40, pt->y + 1);
	ft_draw_line_white(w3d, pt->x + 0, pt->x + 40, pt->y + 2);
	ft_draw_line_white(w3d, pt->x + 1, pt->x + 39, pt->y + 3);
	ft_draw_line_white(w3d, pt->x + 1, pt->x + 39, pt->y + 4);
	ft_draw_line_white(w3d, pt->x + 2, pt->x + 38, pt->y + 5);
	ft_draw_line_white(w3d, pt->x + 2, pt->x + 38, pt->y + 6);
	ft_draw_line_white(w3d, pt->x + 3, pt->x + 37, pt->y + 7);
	ft_draw_line_white(w3d, pt->x + 3, pt->x + 37, pt->y + 8);
	ft_draw_line_white(w3d, pt->x + 4, pt->x + 36, pt->y + 9);
	ft_draw_line_white(w3d, pt->x + 5, pt->x + 35, pt->y + 10);
	ft_draw_line_white(w3d, pt->x + 6, pt->x + 34, pt->y + 11);
	ft_draw_line_white(w3d, pt->x + 8, pt->x + 32, pt->y + 12);
	ft_draw_line_white(w3d, pt->x + 10, pt->x + 30, pt->y + 13);
	ft_draw_line_white(w3d, pt->x + 12, pt->x + 28, pt->y + 14);
	ft_draw_line_white(w3d, pt->x + 14, pt->x + 26, pt->y + 15);
	ft_draw_line_white(w3d, pt->x + 18, pt->x + 22, pt->y + 16);
	put_moon_detail(w3d, pt);
}

static void		put_earth_detail(t_w3d *w3d, t_pt *pt)
{
	ft_draw_line_green(w3d, pt->x + 1, pt->x + 2, pt->y + 2);
	ft_draw_line_green(w3d, pt->x, pt->x + 3, pt->y + 3);
	ft_draw_line_green(w3d, pt->x, pt->x + 2, pt->y + 4);
	ft_draw_line_green(w3d, pt->x + 8, pt->x + 9, pt->y + 4);
	ft_draw_line_green(w3d, pt->x + 1, pt->x + 4, pt->y + 7);
	ft_draw_line_green(w3d, pt->x + 4, pt->x + 5, pt->y + 8);
	ft_draw_line_green(w3d, pt->x + 4, pt->x + 6, pt->y + 9);
	ft_draw_line_white(w3d, pt->x + 4, pt->x + 5, pt->y + 1);
	ft_draw_line_white(w3d, pt->x + 8, pt->x + 8, pt->y + 7);
	ft_draw_line_white(w3d, pt->x + 7, pt->x + 7, pt->y + 8);
}

static void		put_earth_or_star(t_w3d *w3d, t_pt *pt, int size, char type)
{
	if (type == 'e')
	{
		ft_draw_line_blue(w3d, pt->x + 3, pt->x + 6, pt->y);
		ft_draw_line_blue(w3d, pt->x + 2, pt->x + 7, pt->y + 1);
		ft_draw_line_blue(w3d, pt->x + 1, pt->x + 8, pt->y + 2);
		ft_draw_line_blue(w3d, pt->x + 0, pt->x + 9, pt->y + 3);
		ft_draw_line_blue(w3d, pt->x + 0, pt->x + 9, pt->y + 4);
		ft_draw_line_blue(w3d, pt->x + 0, pt->x + 9, pt->y + 5);
		ft_draw_line_blue(w3d, pt->x + 0, pt->x + 9, pt->y + 6);
		ft_draw_line_blue(w3d, pt->x + 1, pt->x + 8, pt->y + 7);
		ft_draw_line_blue(w3d, pt->x + 2, pt->x + 7, pt->y + 8);
		ft_draw_line_blue(w3d, pt->x + 3, pt->x + 6, pt->y + 9);
		put_earth_detail(w3d, pt);
	}
	else if (type == 's')
	{
		put_pixel_to_img(w3d, pt->x, pt->y - size, 0xFFFFFF);
		put_pixel_to_img(w3d, pt->x - size, pt->y, 0xFFFFFF);
		put_pixel_to_img(w3d, pt->x + size, pt->y, 0xFFFFFF);
		put_pixel_to_img(w3d, pt->x, pt->y + size, 0xFFFFFF);
	}
}

void			put_sky_and_floor(t_w3d *w3d)
{
	t_pt	cur;

	cur.y = HEIGHT / 2 - 1;
	while (++cur.y < HEIGHT)
	{
		cur.x = -1;
		while (++cur.x < WIDTH)
			put_pixel_to_img(w3d, cur.x, cur.y, 0x003D4C);
	}
	put_moon(w3d, w3d->sky[0]);
	put_earth_or_star(w3d, w3d->sky[1], 0, 'e');
	put_earth_or_star(w3d, w3d->sky[2], 1, 's');
	put_earth_or_star(w3d, w3d->sky[3], 2, 's');
	put_earth_or_star(w3d, w3d->sky[4], 1, 's');
	put_earth_or_star(w3d, w3d->sky[5], 1, 's');
	put_earth_or_star(w3d, w3d->sky[6], 1, 's');
	put_earth_or_star(w3d, w3d->sky[7], 2, 's');
	put_earth_or_star(w3d, w3d->sky[8], 1, 's');
	put_earth_or_star(w3d, w3d->sky[9], 1, 's');
}

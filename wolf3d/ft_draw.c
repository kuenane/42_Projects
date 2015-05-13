/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 10:53:14 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/08 17:35:42 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <mlx.h>

void			put_pixel_to_img(t_w3d *w3d, int x, int y, U_INT color)
{
	void	*adr_ptr;
	void	*color_ptr;

	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		color = mlx_get_color_value(w3d->mlx, color);
		x *= w3d->octpp;
		y *= w3d->size_line;
		adr_ptr = (void*)&(w3d->data[x + y]);
		color_ptr = (void*)&color;
		adr_ptr = ft_memcpy(adr_ptr, color_ptr, w3d->octpp);
	}
}

void			ft_draw_line_white(t_w3d *w3d, int xsrc, int xdst, int y)
{
	while (xsrc <= xdst)
	{
		put_pixel_to_img(w3d, xsrc, y, 0xE9E9DF);
		xsrc++;
	}
}

void			ft_draw_line_grey(t_w3d *w3d, int xsrc, int xdst, int y)
{
	while (xsrc <= xdst)
	{
		put_pixel_to_img(w3d, xsrc, y, 0xCACABC);
		xsrc++;
	}
}

void			ft_draw_line_blue(t_w3d *w3d, int xsrc, int xdst, int y)
{
	while (xsrc <= xdst)
	{
		put_pixel_to_img(w3d, xsrc, y, 0x000080);
		xsrc++;
	}
}

void			ft_draw_line_green(t_w3d *w3d, int xsrc, int xdst, int y)
{
	while (xsrc <= xdst)
	{
		put_pixel_to_img(w3d, xsrc, y, 0x006600);
		xsrc++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 11:25:49 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 16:22:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <libft.h>

void			put_pixel_to_img(t_mlx *mlx, int x, int y, unsigned int color)
{
	void	*adr_ptr;
	void	*color_ptr;

	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		color = mlx_get_color_value(mlx->mlx, color);
		x *= mlx->octpp;
		y *= mlx->size_line;
		adr_ptr = (void*)&(mlx->data[x + y]);
		color_ptr = (void*)&color;
		adr_ptr = ft_memcpy(adr_ptr, color_ptr, mlx->octpp);
	}
}

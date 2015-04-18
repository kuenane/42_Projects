/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 11:26:31 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 15:26:53 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>

#define MX mlx->x
#define MX1 cp1->x
#define MX2 cp2->x
#define MY mlx->y
#define MY1 cp1->y
#define MY2 cp2->y

static void		small_angle(t_mlx *mlx, t_pt *cp1, t_pt *cp2, UINT color)
{
	MX = MX1;
	while (MX <= MX2)
	{
		put_pixel_to_img(mlx, MX, MY1 + ((MY2 - MY1) * (MX - MX1)) /
		(MX2 - MX1), color);
		MX++;
	}
}

static void		big_angle(t_mlx *mlx, t_pt *cp1, t_pt *cp2, UINT color)
{
	swap_two_int(&MX1, &MY1);
	swap_two_int(&MX2, &MY2);
	MX = MX1;
	while (MX >= MX2)
	{
		put_pixel_to_img(mlx, MY1 + ((MY2 - MY1) * (MX - MX1)) /
		(MX2 - MX1), MX, color);
		MX--;
	}
}

static t_pt		*t_pt_cpy(t_pt *src)
{
	t_pt	*new;

	new = (t_pt*)malloc(sizeof(t_pt) * 1);
	new->x = src->x;
	new->y = src->y;
	new->z = src->z;
	return (new);
}

void			put_line_on_img(t_mlx *mlx, t_pt *pt1, t_pt *pt2, UINT color)
{
	t_pt	*cp1;
	t_pt	*cp2;

	cp1 = t_pt_cpy(pt1);
	cp2 = t_pt_cpy(pt2);
	if (abs(MX2 - MX1) >= abs(MY2 - MY1))
	{
		if (MX1 > MX2)
		{
			swap_two_int(&MX1, &MX2);
			swap_two_int(&MY1, &MY2);
		}
		return (small_angle(mlx, cp1, cp2, color));
	}
	if (MY1 <= MY2)
	{
		swap_two_int(&MX1, &MX2);
		swap_two_int(&MY1, &MY2);
	}
	return (big_angle(mlx, cp1, cp2, color));
	free(cp1);
	free(cp2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_expose_and_key2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 09:40:51 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 14:34:00 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

static void		sky_loop_hook(t_w3d *w3d)
{
	int		i;

	i = -1;
	while (++i < NB_STAR)
	{
		if (i > 1)
		{
			w3d->sky[i]->x--;
			if (w3d->sky[i]->x < -1)
				w3d->sky[i]->x += WIDTH;
		}
	}
}

int				manage_loop_hook(void *param)
{
	t_w3d	*w3d;
	clock_t	clck;

	w3d = (t_w3d*)param;
	clck = clock();
	if (clck > w3d->sky_clk + CLK_TIME_SKY)
	{
		w3d->sky_clk = clck;
		sky_loop_hook(w3d);
		manage_shoot_hook(w3d);
		manage_expose_hook(w3d);
	}
	return (1);
}

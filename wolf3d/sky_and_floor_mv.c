/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor_mv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:37:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/08 17:38:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void			move_sky_r_key(t_w3d *w3d)
{
	int		i;

	i = -1;
	while (++i < NB_STAR)
	{
		w3d->sky[i]->x -= SKY_SPEED;
		if (i > 1)
			if (w3d->sky[i]->x < -5)
				w3d->sky[i]->x += WIDTH;
		if (i == 0)
			if (w3d->sky[i]->x < -50)
				w3d->sky[i]->x = WIDTH4_50;
		if (i == 1)
			if (w3d->sky[i]->x < -50)
				w3d->sky[i]->x = WIDTH4_50;
	}
}

void			move_sky_l_key(t_w3d *w3d)
{
	int		i;

	i = -1;
	while (++i < NB_STAR)
	{
		w3d->sky[i]->x += SKY_SPEED;
		if (i > 1)
			if (w3d->sky[i]->x > WIDTH)
				w3d->sky[i]->x -= WIDTH;
		if (i == 0)
			if (w3d->sky[i]->x > WIDTH4_50)
				w3d->sky[i]->x = -50;
		if (i == 1)
			if (w3d->sky[i]->x > WIDTH4_50)
				w3d->sky[i]->x = -50;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 13:56:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 08:05:47 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void			init_player_pos(t_w3d *w3d)
{
	int		i;
	int		j;

	i = -1;
	while (++i < w3d->hmap)
	{
		j = -1;
		while (++j < w3d->wmap)
		{
			if (!w3d->map[i][j])
			{
				w3d->posy = j * 64 + 32;
				w3d->posx = i * 64 + 32;
				if (j + 1 < w3d->wmap && !w3d->map[i][j + 1])
					w3d->ang = 0;
				else
					w3d->ang = 270;
				return ;
			}
		}
	}
	ft_exit("Invalid map.");
}

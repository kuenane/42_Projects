/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:37:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/08 17:38:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

static t_pt		**new_t_pt_tab(int size)
{
	t_pt	**tab;
	int		i;

	tab = (t_pt**)v_malloc(sizeof(t_pt*) * size);
	i = -1;
	while (++i < size)
		tab[i] = (t_pt*)v_malloc(sizeof(t_pt));
	return (tab);
}

t_pt			**init_sky(void)
{
	t_pt	**tab;

	tab = new_t_pt_tab(NB_STAR);
	tab[0]->x = 0;
	tab[0]->y = 0;
	tab[1]->x = WIDTH2;
	tab[1]->y = 50;
	tab[2]->x = 70;
	tab[2]->y = 50;
	tab[3]->x = 170;
	tab[3]->y = 120;
	tab[4]->x = 350;
	tab[4]->y = 170;
	tab[5]->x = 290;
	tab[5]->y = 10;
	tab[6]->x = 470;
	tab[6]->y = 50;
	tab[7]->x = 550;
	tab[7]->y = 140;
	tab[8]->x = 650;
	tab[8]->y = 80;
	tab[9]->x = 710;
	tab[9]->y = 150;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:06:38 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 18:09:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		apply_good_keycode(t_pt *pt, int keycode)
{
	if (keycode == 65361)
		pt->x = pt->x - 10;
	else if (keycode == 65362)
		pt->y = pt->y - 10;
	else if (keycode == 65363)
		pt->x = pt->x + 10;
	else
		pt->y = pt->y + 10;
}

t_pt			**hook_move_map(t_pt **tab, int keycode)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j].z != EOL)
		{
			apply_good_keycode(&tab[i][j], keycode);
			j++;
		}
		i++;
	}
	return (tab);
}

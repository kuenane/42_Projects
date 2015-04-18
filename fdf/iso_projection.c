/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 10:50:13 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 18:14:32 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define CTE1 1
#define CTE2 0.5

static void		calc_iso_projection(t_pt *pt)
{
	pt->x = CTE1 * pt->x - CTE2 * pt->y;
	pt->y = pt->z + (CTE1 / 2) * pt->x + (CTE2 / 2) * pt->y;
}

t_pt			**apply_iso_projection(t_pt **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j].z != EOL)
		{
			tab[i][j].x = 1500 + ((MLX_SIZE) * (j + 1));
			tab[i][j].y = 1500 + ((MLX_SIZE) * (i + 1));
			tab[i][j].z *= MLX_SIZE / Z_SIZE;
			calc_iso_projection(&tab[i][j]);
			j++;
		}
		i++;
	}
	return (tab);
}

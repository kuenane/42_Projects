/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:36:16 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 16:18:01 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <libft.h>
#include <math.h>

static int		previous_len(t_pt *previous)
{
	int		i;

	i = 0;
	while (previous[i].z != EOL)
		i++;
	return (i);
}

void			put_map(t_mlx *mlx, t_pt **tab)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j].z != EOL)
		{
			if (j)
				put_line_on_img(mlx, &tab[i][j - 1], &tab[i][j], MLX_COLOR);
			if (i && len > j)
				put_line_on_img(mlx, &tab[i - 1][j], &tab[i][j], MLX_COLOR);
			j++;
		}
		i++;
		if (i > 0)
			len = previous_len(tab[i - 1]);
	}
}

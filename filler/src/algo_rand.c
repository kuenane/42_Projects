/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:23:34 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 16:52:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <stdlib.h>

static int		ft_rand(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

void			define_piece_position(t_env *env)
{
	t_pos	curpos;

	curpos.h = ft_rand(0, MAPH - PIECEH);
	curpos.w = ft_rand(0, MAPW - PIECEW);
	while (!is_pos_valid(env, curpos))
	{
		curpos.h = ft_rand(0, MAPH - PIECEH);
		curpos.w = ft_rand(0, MAPW - PIECEW);
	}
	POSH = curpos.h;
	POSW = curpos.w;
}

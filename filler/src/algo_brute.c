/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_brute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:23:34 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 17:09:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			define_piece_position(t_env *env)
{
	t_pos	curpos;

	curpos.h = -1;
	while (++curpos.h <= MAPH - PIECEH)
	{
		curpos.w = -1;
		while (++curpos.w <= MAPW - PIECEW)
		{
			if (is_pos_valid(env, curpos))
			{
				POSH = curpos.h;
				POSW = curpos.w;
				return ;
			}
		}
	}
}

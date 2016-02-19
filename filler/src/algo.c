/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:23:34 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 17:09:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		calc_avg_proxi(t_env *env)
{
	t_pos	curpos;
	int		total;
	int		nb_input;

	total = 0;
	nb_input = 0;
	curpos.h = -1;
	while (++curpos.h <= MAPH - PIECEH)
	{
		curpos.w = -1;
		while (++curpos.w <= MAPW - PIECEW)
		{
			if (is_pos_valid(env, curpos))
			{
				total += calc_piece_proximity(env, curpos);
				nb_input++;
			}
		}
	}
	return (total / nb_input);
}

static t_bool	is_proxi_putable(t_env *env, int proxi)
{
	t_pos	curpos;

	curpos.h = -1;
	while (++curpos.h <= MAPH - PIECEH)
	{
		curpos.w = -1;
		while (++curpos.w <= MAPW - PIECEW)
		{
			if (is_pos_valid(env, curpos)
			&& calc_piece_proximity(env, curpos) == proxi)
			{
				POSH = curpos.h;
				POSW = curpos.w;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

static void		jail_algo(t_env *env)
{
	int		avg_proxi;
	int		cur_inc;
	int		maxmap;

	avg_proxi = calc_avg_proxi(env);
	cur_inc = 0;
	maxmap = (MAPH > MAPW) ? MAPH : MAPW;
	while (avg_proxi - cur_inc > 0 || avg_proxi + cur_inc < maxmap)
	{
		if (avg_proxi - cur_inc > 0
		&& is_proxi_putable(env, avg_proxi - cur_inc))
			return ;
		if (avg_proxi + cur_inc < maxmap
		&& is_proxi_putable(env, avg_proxi + cur_inc))
			return ;
		cur_inc++;
	}
}

void			define_piece_position(t_env *env)
{
	t_pos	curpos;

	if (is_ennemy_out(env))
	{
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
	else
		jail_algo(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:18:54 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 17:10:18 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		is_pos_valid2(t_env *env, t_pos *piece, t_pos *map, t_bool *er)
{
	if (PIECEXY(piece->h, piece->w) == '*')
	{
		if (IS_E(MAPXY(map->h, map->w)))
			return (-1);
		if (IS_P(MAPXY(map->h, map->w)))
		{
			if (*er)
				return (-1);
			*er = TRUE;
		}
	}
	return (0);
}

t_bool			is_pos_valid(t_env *env, t_pos curpos)
{
	t_pos		map;
	t_pos		piece;
	t_bool		erased;

	erased = FALSE;
	piece.h = 0;
	while (piece.h < PIECEH)
	{
		map.h = curpos.h + piece.h;
		piece.w = 0;
		while (piece.w < PIECEW)
		{
			map.w = curpos.w + piece.w;
			if (is_pos_valid2(env, &piece, &map, &erased))
				return (FALSE);
			piece.w++;
			map.w++;
		}
		piece.h++;
		map.h++;
	}
	return (erased);
}

t_bool			is_ennemy_out(t_env *env)
{
	t_pos		curpos;

	curpos.h = -1;
	while (++curpos.h < MAPH)
	{
		curpos.w = -1;
		while (++curpos.w < MAPW)
		{
			if (curpos.w == ELOW)
				return (FALSE);
		}
	}
	return (TRUE);
}

int				calc_proximity_one_point(t_env *env, t_pos *pos)
{
	t_pos		curpos;
	int			curdist;

	curdist = 0;
	while (++curdist)
	{
		curpos.h = ft_max(pos->h - curdist, 0);
		while (curpos.h <= pos->h + curdist && curpos.h != MAPH)
		{
			curpos.w = ft_max(pos->w - curdist, 0);
			while (curpos.w <= pos->w + curdist && curpos.w != MAPW)
			{
				if ((curpos.h != pos->h || curpos.w != pos->w)
				&& curpos.h >= 0 && curpos.h < MAPH
				&& curpos.w >= 0 && curpos.w < MAPW
				&& IS_E(MAPXY(curpos.h, curpos.w)))
					return (curdist);
				curpos.w++;
			}
			curpos.h++;
		}
	}
	return ((MAPH > MAPW) ? MAPH : MAPW);
}

int				calc_piece_proximity(t_env *env, t_pos pos)
{
	t_pos		piece;
	int			proxi;
	int			ret;
	t_pos		tmp;

	proxi = (MAPH > MAPW) ? MAPH : MAPW;
	piece.h = -1;
	while (++piece.h < PIECEH)
	{
		piece.w = -1;
		while (++piece.w < PIECEW)
		{
			tmp.h = pos.h + piece.h;
			tmp.w = pos.w + piece.w;
			if (IS_P(MAPXY(tmp.h, tmp.w))
			&& (ret = calc_proximity_one_point(env, &tmp)) < proxi)
				proxi = ret;
		}
	}
	return (proxi);
}

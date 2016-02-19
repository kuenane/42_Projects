/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dw31 <dw31@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:52:18 by dw31              #+#    #+#             */
/*   Updated: 2016/02/19 17:18:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <viewer.h>

static void		calc_score(t_env *env, int *p1, int *p2)
{
	int		i;
	int		j;

	*p1 = 0;
	*p2 = 0;
	i = -1;
	while (++i < MAPH)
	{
		j = -1;
		while (++j < MAPW)
		{
			if (MAPXY(i, j) == 'o' || MAPXY(i, j) == 'O')
				(*p1)++;
			else if (MAPXY(i, j) == 'x' || MAPXY(i, j) == 'X')
				(*p2)++;
		}
	}
}

static void		set_score(t_env *env)
{
	int		p1;
	int		p2;
	char	*tmpstring;

	calc_score(env, &p1, &p2);
	tmpstring = v_strjoin((P1_NAME) ? P1_NAME : "P1", " (blue): ");
	tmpstring = v_strjoin_free(tmpstring, v_itoa(p1), TRUE, TRUE);
	tmpstring = v_strjoin_free(tmpstring, "            ", TRUE, FALSE);
	tmpstring = v_strjoin_free(tmpstring, (P2_NAME) ? P2_NAME : "P2", 1, 0);
	tmpstring = v_strjoin_free(tmpstring, " (green): ", TRUE, FALSE);
	tmpstring = v_strjoin_free(tmpstring, v_itoa(p2), TRUE, TRUE);
	SDL_SetWindowTitle(WIN, tmpstring);
	ft_free(tmpstring);
}

static t_bool	misc_calc_and_ret(t_env *env)
{
	OUT_SQ = (DEF_WINW < DEF_WINH) ? DEF_WINW : DEF_WINH;
	OUT_SQ /= (MAPW > MAPH) ? MAPW : MAPH;
	BORDER_SQ = OUT_SQ / 10;
	IN_SQ = OUT_SQ - BORDER_SQ * 2;
	RECT_SDL.w = IN_SQ;
	RECT_SDL.h = IN_SQ;
	WINH = (MAPH * IN_SQ) + ((MAPH + 1) * BORDER_SQ);
	WINW = (MAPW * IN_SQ) + ((MAPW + 1) * BORDER_SQ);
	SDL_SetWindowSize(WIN, WINW, WINH);
	set_score(env);
	return (TRUE);
}

static t_bool	get_players_names(t_env *env)
{
	int		ret;

	while ((ret = get_next_line(0, &LINE)) > 0
	&& ft_strncmp("Plateau ", LINE, 8))
	{
		if (!P1_NAME && !ft_strncmp("$$$ exec p1 : [", LINE, 15))
		{
			P1_NAME = v_strndup(ft_strchr(LINE, '[') + 1, ft_strchr(LINE, ']')
				- ft_strchr(LINE, '[') - 1);
			if (ft_strrchr(P1_NAME, '/'))
				P1_NAME = v_replace_free2(P1_NAME, ft_strrchr(P1_NAME, '/')
				+ 1, FALSE);
		}
		else if (!P2_NAME && !ft_strncmp("$$$ exec p2 : [", LINE, 15))
		{
			P2_NAME = v_strndup(ft_strchr(LINE, '[') + 1, ft_strchr(LINE, ']')
				- ft_strchr(LINE, '[') - 1);
			if (ft_strrchr(P2_NAME, '/'))
				P2_NAME = v_replace_free2(P2_NAME, ft_strrchr(P2_NAME, '/')
					+ 1, FALSE);
		}
	}
	if (ret <= 0)
		return (FALSE);
	return (TRUE);
}

t_bool			get_map(t_env *env)
{
	int		ret;
	int		i;

	if (!get_players_names(env))
		return (FALSE);
	i = ft_strchr(LINE, ' ') + 1 - LINE;
	MAPH = ft_atoi(&LINE[i]);
	MAPW = ft_atoi(ft_strchr(&LINE[i], ' ') + 1);
	if (get_next_line(0, &LINE) <= 0)
		return (FALSE);
	MAP = v_strtabnew(MAPH);
	i = -1;
	while ((ret = get_next_line(0, &LINE)) > 0 && ft_atoi(LINE) == ++i)
	{
		if (i == MAPH)
			return (FALSE);
		MAPX(i) = v_strdup(ft_strchr(LINE, ' ') + 1);
		if ((int)ft_strlen(MAPX(i)) != MAPW)
			return (FALSE);
	}
	if (ret <= 0 || ft_strncmp("Piece ", LINE, 6))
		return (FALSE);
	return (misc_calc_and_ret(env));
}

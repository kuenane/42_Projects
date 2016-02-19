/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 00:18:54 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 17:10:04 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		read_player_infos(t_env *env)
{
	char	*open_hook;

	if (get_next_line(0, &LINE) <= 0 || ft_strlen(LINE) < 17
	|| ft_strncmp(LINE, "$$$ exec p", 10))
		return (-1);
	P_NB = ft_atoi(ft_strchr(LINE, 'p') + 1);
	open_hook = ft_strchr(LINE, '[') + 1;
	P_NAME = v_strsub(open_hook, 0, ft_strchr(LINE, ']') - open_hook);
	return (0);
}

int		read_map(t_env *env)
{
	int		i;
	int		ret;

	if (get_next_line(0, &LINE) <= 0)
		return (-1);
	i = ft_strchr(LINE, ' ') + 1 - LINE;
	MAPH = ft_atoi(&LINE[i]);
	MAPW = ft_atoi(ft_strchr(&LINE[i], ' ') + 1);
	if (get_next_line(0, &LINE) <= 0)
		return (-1);
	MAP = v_strtabnew(MAPH);
	i = -1;
	while ((ret = get_next_line(0, &LINE)) > 0 && ft_atoi(LINE) == ++i)
	{
		if (i == MAPH)
			return (-1);
		MAPX(i) = v_strdup(ft_strchr(LINE, ' ') + 1);
		if ((int)ft_strlen(MAPX(i)) != MAPW)
			return (-1);
	}
	if (ret <= 0 || ft_strncmp("Piece ", LINE, 6))
		return (-1);
	return (0);
}

int		read_piece(t_env *env)
{
	int		i;

	i = ft_strchr(LINE, ' ') + 1 - LINE;
	PIECEH = ft_atoi(&LINE[i]);
	PIECEW = ft_atoi(ft_strchr(&LINE[i], ' ') + 1);
	PIECE = v_strtabnew(PIECEH);
	i = -1;
	while (++i < PIECEH && get_next_line(0, &LINE) > 0)
	{
		PIECEX(i) = v_strdup(LINE);
		if ((int)ft_strlen(PIECEX(i)) != PIECEW)
			return (-1);
	}
	if (i != PIECEH)
		return (-1);
	return (0);
}

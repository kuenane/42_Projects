/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 10:59:57 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/13 12:17:59 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define ADDLINE env->input_save = add_str_strtab(env->input_save, line)
#define FLINE (ft_free(line))

static t_bool	is_a_room(const char *line, t_bool sef)
{
	int		i;
	int		j;

	if (!sef && (ft_strnequ(line, "start", 5) || ft_strnequ(line, "end", 3)))
		return (FALSE);
	i = 0;
	while (line[i] != ' ' && line[i])
		i++;
	if (!line[i++])
		return (FALSE);
	j = i;
	while (line[j] != ' ' && line[j])
		j++;
	if (!line[j])
		return (FALSE);
	if (!ft_str_isint2(&line[i]) || !ft_str_isint(&line[j + 1]))
		return (FALSE);
	return (TRUE);
}

static t_bool	is_a_tube(const char *line)
{
	int		i;

	i = 0;
	while (line[i] != '-' && line[i])
		i++;
	if (!line[i])
		return (FALSE);
	return (TRUE);
}

static t_bool	start_end_found(t_env *env, char *line, t_bool isstart)
{
	int		ret;

	if ((ret = get_next_line(0, &line)) < 0)
		ft_exit(ERR_MSG);
	if (!ret || (isstart && START_ROOM != -1) || (!isstart && END_ROOM != -1)
		|| !is_a_room(line, TRUE))
		return (ft_free(line), FALSE);
	put_room(env, line);
	if (isstart)
		return (START_ROOM = NB_ROOMS - 1, ft_free(line), TRUE);
	return (END_ROOM = NB_ROOMS - 1, ft_free(line), TRUE);
}

static t_bool	apply_line(t_env *env, char *line, t_bool *roompart)
{
	if (*roompart == TRUE && ft_strequ(line, "##start"))
		return (ADDLINE, ft_free(line), start_end_found(env, line, TRUE));
	if (*roompart == TRUE && ft_strequ(line, "##end"))
		return (ADDLINE, ft_free(line), start_end_found(env, line, FALSE));
	if (line[0] == '#')
		return (ADDLINE, ft_free(line), TRUE);
	if (*roompart == TRUE && is_a_room(line, FALSE))
		return (put_room(env, line));
	if (is_a_tube(line))
		return (*roompart = FALSE, put_tube(env, line));
	return (ft_free(line), FALSE);
}

void			init_env(t_env *env)
{
	char	*line;
	int		ret;
	t_bool	roompart;

	START_ROOM = -1;
	END_ROOM = -1;
	roompart = TRUE;
	LIT_PATHTAB = NULL;
	SIZE_LIT_PATH = 2147483647;
	if (get_next_line(0, &line) < 0)
		ft_exit(ERR_MSG);
	if (!ft_str_isint(line) || (NB_ANTS = ft_atoi(line)) <= 0)
		ft_exit(ERR_MSG);
	env->input_save = add_str_strtab(v_strtabnew(0), line);
	ft_free(line);
	while ((ret = get_next_line(0, &line)) > 0)
		if (!apply_line(env, line, &roompart))
			break ;
	if (ret < 0)
		ft_exit(ERR_MSG);
	put_ants(env);
}

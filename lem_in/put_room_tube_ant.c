/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_room_tube_ant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 10:59:57 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/14 09:10:16 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define FREE3 (ft_free(name1), ft_free(name2), ft_free(line))

static void		add_tube_to_room(t_env *env, char *name1, char *name2)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (ft_strcmp(ROOM(i1)->name, name1))
		i1++;
	while (ft_strcmp(ROOM(i2)->name, name2))
		i2++;
	ROOM(i1)->tubes_id =
		add_int_inttab(ROOM(i1)->tubes_id, ROOM(i2)->id, ROOM(i1)->nb_tubes);
	ROOM(i1)->nb_tubes++;
	ROOM(i2)->tubes_id =
		add_int_inttab(ROOM(i2)->tubes_id, ROOM(i1)->id, ROOM(i2)->nb_tubes);
	ROOM(i2)->nb_tubes++;
}

static t_bool	is_room_already_defined(t_env *env, char *name)
{
	int		i;

	i = 0;
	while (i < NB_ROOMS)
	{
		if (ft_strequ(ROOM(i)->name, name))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool			put_room(t_env *env, char *line)
{
	t_room	*newroom;
	int		i;

	if (line[0] == 'L')
		ft_exit(ERR_MSG);
	newroom = (t_room*)v_malloc(sizeof(t_room));
	ft_bzero(newroom, sizeof(t_room));
	newroom->id = NB_ROOMS;
	i = 0;
	while (line[i] != ' ')
		i++;
	newroom->name = ft_strncpy(v_strnew(i), line, i);
	newroom->posx = ft_atoi(&line[++i]);
	while (line[i] != ' ')
		i++;
	i++;
	newroom->posy = ft_atoi(&line[i]);
	if (is_room_already_defined(env, newroom->name))
		return (ft_free(newroom->name), ft_free(newroom), FALSE);
	if (NB_ROOMS)
		ROOMTAB = add_troom_totab(ROOMTAB, newroom, NB_ROOMS);
	else
		ROOMTAB = new_troomtab(newroom);
	env->input_save = add_str_strtab(env->input_save, line);
	return (NB_ROOMS++, TRUE);
}

t_bool			put_tube(t_env *env, char *line)
{
	int		i;
	char	*name1;
	char	*name2;

	i = 0;
	while (line[i] != '-')
		i++;
	name1 = v_strndup(line, i);
	if (!is_room_already_defined(env, name1))
		return (ft_free(name1), ft_free(line), FALSE);
	name2 = v_strdup(&line[++i]);
	if (!is_room_already_defined(env, name2))
		return (FREE3, FALSE);
	add_tube_to_room(env, name1, name2);
	env->input_save = add_str_strtab(env->input_save, line);
	return (FREE3, TRUE);
}

void			put_ants(t_env *env)
{
	int		i;

	env->ants = (t_ant**)v_malloc(sizeof(t_ant*) * NB_ANTS);
	i = -1;
	while (++i < NB_ANTS)
	{
		ANT(i) = (t_ant*)v_malloc(sizeof(t_ant));
		ANT(i)->id = i;
		ANT(i)->pos = START_ROOM;
	}
}

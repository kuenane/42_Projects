/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 16:14:54 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/16 09:38:32 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

# define DEBUG_MODE FALSE

# define ANT(x) env->ants[x]
# define NB_ANTS env->nb_ants
# define ROOMTAB env->anthill.rooms
# define ROOM(x) env->anthill.rooms[x]
# define NB_ROOMS env->anthill.nb_rooms
# define TUBE(x,y) env->anthill.rooms[x]->tubes_id[y]
# define NB_TUBES(x) env->anthill.rooms[x]->nb_tubes
# define START_ROOM env->anthill.start_room
# define END_ROOM env->anthill.end_room
# define LIT_PATHTAB env->lit_path
# define LIT_PATH(x) env->lit_path[x]
# define SIZE_LIT_PATH env->size_lit_path
# define ERR_MSG "\033[31mERROR\033[0m"
# define DEB_START_MSG " ---------------\n| DEBUG ENABLED |\n --------------- "
# define DEB_END_MSG " ---------------\n"

typedef struct		s_ant
{
	int				id;
	int				pos;
}					t_ant;

typedef struct		s_room
{
	int				id;
	char			*name;
	int				*tubes_id;
	int				nb_tubes;
	int				posx;
	int				posy;
}					t_room;

typedef struct		s_anthill
{
	t_room			**rooms;
	int				nb_rooms;
	int				start_room;
	int				end_room;
}					t_anthill;

typedef struct		s_env
{
	char			**input_save;
	t_ant			**ants;
	int				nb_ants;
	t_anthill		anthill;
	int				*lit_path;
	int				size_lit_path;
}					t_env;

typedef struct		s_search
{
	int				id;
	int				index;
}					t_search;

t_room				*ft_newtroom(int id, char *name, int posx, int posy);
t_room				**add_troom_totab(t_room **tab, t_room *toadd, int tabsize);
t_room				**new_troomtab(t_room *toadd);
void				init_env(t_env *env);
t_bool				put_room(t_env *env, char *line);
t_bool				put_tube(t_env *env, char *line);
void				put_ants(t_env *env);
void				put_lit_path(t_env *env);
void				send_ants(t_env *env);
t_bool				is_linked_with_endroom(t_env *env, int my_id);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 16:14:04 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 16:51:35 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>

# define P_NB env->player_nb
# define P_NAME env->player_name
# define MAP env->map
# define MAPX(x) env->map[x]
# define MAPXY(x, y) env->map[x][y]
# define MAPW env->tmap.w
# define MAPH env->tmap.h
# define PIECE env->piece
# define PIECEX(x) env->piece[x]
# define PIECEXY(x, y) env->piece[x][y]
# define PIECEH env->tpiece.h
# define PIECEW env->tpiece.w
# define POSH env->pos.h
# define POSW env->pos.w
# define POS_IS_DEFINED env->pos_defined
# define LINE env->line
# define PUP ((P_NB == 1) ? 'O' : 'X' )
# define PLOW ((P_NB == 1) ? 'o' : 'x' )
# define IS_P(x) ((x == PUP || x == PLOW) ? TRUE : FALSE)
# define EUP ((P_NB != 1) ? 'O' : 'X' )
# define ELOW ((P_NB != 1) ? 'o' : 'x' )
# define IS_E(x) ((x == EUP || x == ELOW) ? TRUE : FALSE)

typedef struct	s_pos
{
	int		w;
	int		h;
}				t_pos;

typedef struct	s_env
{
	int		player_nb;
	char	*player_name;
	char	**map;
	t_pos	tmap;
	char	**piece;
	t_pos	tpiece;
	t_pos	pos;
	char	*line;
}				t_env;

int				read_player_infos(t_env *env);
int				read_map(t_env *env);
int				read_piece(t_env *env);
t_bool			is_pos_valid(t_env *env, t_pos curpos);
t_bool			is_ennemy_out(t_env *env);
int				calc_proximity_one_point(t_env *env, t_pos *pos);
int				calc_piece_proximity(t_env *env, t_pos pos);
void			define_piece_position(t_env *env);

#endif

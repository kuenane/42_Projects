/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 16:14:04 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 17:14:37 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H

# include <libft.h>
# include <SDL.h>

# define DEF_WINW 960
# define DEF_WINH 720
# define DEF_TITLE "wide-aze filler viewer"
# define WIN env->win
# define WINREND env->winrend
# define CLOSEWIN_RECEIVED (env.events.window.event == SDL_WINDOWEVENT_CLOSE)
# define ESC_PRESSED (env.events.key.keysym.sym == SDLK_ESCAPE)
# define MAP env->map
# define MAPX(x) env->map[x]
# define MAPXY(x, y) env->map[x][y]
# define MAPH env->maph
# define MAPW env->mapw
# define OUT_SQ env->out_sq
# define IN_SQ env->in_sq
# define BORDER_SQ env->border_sq
# define RECT_SDL env->rect_sdl
# define WINH env->winh
# define WINW env->winw
# define LINE env->line
# define P1_NAME env->p1_name
# define P2_NAME env->p2_name

typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Event		events;
	SDL_Rect		rect_sdl;
	SDL_Renderer	*winrend;
	char			**map;
	int				winh;
	int				winw;
	int				maph;
	int				mapw;
	int				out_sq;
	int				in_sq;
	int				border_sq;
	char			*line;
	char			*p1_name;
	char			*p2_name;
}				t_env;

t_bool			get_map(t_env *env);
void			redraw_the_map(t_env *env);

#endif

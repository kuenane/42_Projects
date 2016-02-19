/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:33:34 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/19 17:11:06 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <viewer.h>

static int		init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_putendl_fd_ret("SDL_Init error", 2, -1);
	if (!(WIN = SDL_CreateWindow(DEF_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, DEF_WINW, DEF_WINH, SDL_WINDOW_SHOWN)))
		ft_putendl_fd_ret("SDL_Init error", 2, -1);
	return (0);
}

static void		reset_struct(t_env *env)
{
	while (--MAPH >= 0)
		ft_free(MAPX(MAPH));
	ft_free(MAP);
	OUT_SQ = 0;
	IN_SQ = 0;
	BORDER_SQ = 0;
	RECT_SDL.x = 0;
	RECT_SDL.y = 0;
	RECT_SDL.w = 0;
	RECT_SDL.h = 0;
	WINH = 0;
	WINW = 0;
}

static int		leave_properly_sdl(t_env *env)
{
	SDL_DestroyWindow(WIN);
	SDL_Quit();
	return (0);
}

int				main(void)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	if (init_sdl(&env))
		return (1);
	while (42)
	{
		if ((SDL_PollEvent(&env.events))
		&& (CLOSEWIN_RECEIVED || ESC_PRESSED))
			break ;
		if (get_map(&env))
		{
			redraw_the_map(&env);
			reset_struct(&env);
		}
	}
	return (leave_properly_sdl(&env));
}

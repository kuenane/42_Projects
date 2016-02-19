/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dw31 <dw31@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:50:47 by dw31              #+#    #+#             */
/*   Updated: 2016/02/19 17:17:47 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <viewer.h>

#define POS_SQ(x) ((IN_SQ * x) + (BORDER_SQ * (x + 1)))
#define C_BLUE 'o'
#define C_DBLUE 'O'
#define C_GREEN 'x'
#define C_DGREEN 'X'
#define C_GREY '.'
#define SET_COLOR_BG SDL_SetRenderDrawColor(WINREND, 23, 127, 117, 255)
#define SET_COLOR_BLUE SDL_SetRenderDrawColor(WINREND, 0, 0, 240, 255)
#define SET_COLOR_DBLUE SDL_SetRenderDrawColor(WINREND, 0, 0, 102, 255)
#define SET_COLOR_GREEN SDL_SetRenderDrawColor(WINREND, 0, 204, 0, 255)
#define SET_COLOR_DGREEN SDL_SetRenderDrawColor(WINREND, 0, 102, 0, 255)
#define SET_COLOR_GREY SDL_SetRenderDrawColor(WINREND, 204, 204, 204, 30)
#define TRANSP_ON SDL_SetRenderDrawBlendMode(WINREND, SDL_BLENDMODE_BLEND)
#define TRANSP_OFF SDL_SetRenderDrawBlendMode(WINREND, SDL_BLENDMODE_NONE)

static void		draw_a_rect(t_env *env, int posh, int posw, char cur)
{
	if (cur == C_BLUE)
		SET_COLOR_BLUE;
	else if (cur == C_DBLUE)
		SET_COLOR_DBLUE;
	else if (cur == C_GREEN)
		SET_COLOR_GREEN;
	else if (cur == C_DGREEN)
		SET_COLOR_DGREEN;
	else if (cur == C_GREY)
		SET_COLOR_GREY;
	RECT_SDL.x = posw;
	RECT_SDL.y = posh;
	SDL_RenderFillRect(WINREND, &RECT_SDL);
}

void			redraw_the_map(t_env *env)
{
	int		i;
	int		j;

	SDL_DestroyRenderer(WINREND);
	if (!(WINREND = SDL_CreateRenderer(WIN, -1, SDL_RENDERER_ACCELERATED)))
		return ;
	SET_COLOR_BG;
	SDL_RenderClear(WINREND);
	TRANSP_ON;
	i = -1;
	while (++i < MAPH)
	{
		j = -1;
		while (++j < MAPW)
			draw_a_rect(env, POS_SQ(i), POS_SQ(j), MAPXY(i, j));
	}
	SDL_RenderPresent(WINREND);
	TRANSP_OFF;
}

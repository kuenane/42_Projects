/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 22:33:34 by wide-aze          #+#    #+#             */
/*   Updated: 2015/11/26 23:24:28 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void		reset_map_and_piece(t_env *env)
{
	while (--MAPH >= 0)
		ft_free(MAPX(MAPH));
	ft_free(MAP);
	MAPH = 0;
	MAPW = 0;
	while (--PIECEH >= 0)
		ft_free(PIECEX(PIECEH));
	ft_free(PIECE);
	PIECEH = 0;
	PIECEW = 0;
	POSH = 0;
	POSW = 0;
}

static void		write_position(t_env *env)
{
	ft_putnbr(POSH);
	ft_putchar(' ');
	ft_putnbr(POSW);
	ft_putchar('\n');
}

int				main(void)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	if (read_player_infos(&env))
		return (ft_putendl_fd_ret("error", 2, 1));
	while (!read_map(&env) && !read_piece(&env))
	{
		define_piece_position(&env);
		write_position(&env);
		reset_map_and_piece(&env);
	}
	return (0);
}

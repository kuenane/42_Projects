/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 07:44:42 by ngoguey           #+#    #+#             */
/*   Updated: 2015/02/27 15:40:34 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phi.h>
#include <mlx.h>

int				phi_init_mlx(t_env *e)
{
	t_graph		*g;

	g = &(e->g);
	if (!(g->serv = mlx_init()))
		return (ft_dprintf(2, CONNECTION_FAIL), 1);
	if (!(g->win = mlx_new_window(g->serv, WIN_X, WIN_Y, "Philosophers")))
		return (ft_dprintf(2, WINDOW_FAIL), 1);
	mlx_loop_hook(g->serv, &phi_loop_hook, g);
	if ((g->s.img = mlx_new_image(g->serv, WIN_X, WIN_Y)) == NULL)
		return (ft_dprintf(2, IMAGE_FAIL), 1);
	if ((g->s.dat = mlx_get_data_addr(g->s.img, &g->s.bpp,
									&g->s.lsz, &g->s.end)) == NULL)
		return (ft_dprintf(2, IMAGE_DATA_FAIL), 1);
	return (0);
}

int				phi_redraw_surface(t_env *e)
{
	if (e->g.redraw)
	{
		phi_redraw_image(e);
		phi_put_sticks(e);
	}
	mlx_put_image_to_window(e->g.serv, e->g.win, e->g.s.img, 0, 0);
	phi_put_strings(e);
	e->g.redraw = 0;
	e->g.redrawt = 0;
	return (0);
}

int				phi_quit_mlx(t_graph *g)
{
	mlx_destroy_image(g->serv, g->s.img);
	mlx_destroy_window(g->serv, g->win);
	return (0);
}

void			phi_pause_mlx(t_env *e)
{
	mlx_loop(e->g.serv);
	return ;
}

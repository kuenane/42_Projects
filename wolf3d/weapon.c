/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:02:50 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 14:34:28 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <mlx.h>

#define WTAB w3d->weap_imgs
#define WMENU w3d->menu_img
#define WGAME w3d->game_img
#define WPAUSE w3d->pause_img

void	load_weapon(t_w3d *w3d)
{
	int		tmp;

	WTAB = (void**)v_malloc(sizeof(void*) * 4);
	WTAB[0] = mlx_xpm_file_to_image(w3d->mlx, "xpm/weap0-0.xpm", &tmp, &tmp);
	WTAB[1] = mlx_xpm_file_to_image(w3d->mlx, "xpm/weap1-0.xpm", &tmp, &tmp);
	WTAB[2] = mlx_xpm_file_to_image(w3d->mlx, "xpm/weap0-1.xpm", &tmp, &tmp);
	WTAB[3] = mlx_xpm_file_to_image(w3d->mlx, "xpm/weap1-1.xpm", &tmp, &tmp);
	w3d->weap = 2;
	w3d->weap_state = 0;
	w3d->weap_clk = 0;
	if (!WTAB[0] || !WTAB[1] || !WTAB[2] || !WTAB[3])
		ft_exit("Error: cannot import weapon file");
	WMENU = mlx_xpm_file_to_image(w3d->mlx, "xpm/menu.xpm", &tmp, &tmp);
	WGAME = mlx_xpm_file_to_image(w3d->mlx, "xpm/game.xpm", &tmp, &tmp);
	WPAUSE = mlx_xpm_file_to_image(w3d->mlx, "xpm/pause.xpm", &tmp, &tmp);
	if (!w3d->menu_img)
		ft_exit("Error: cannot load menu image");
	if (!w3d->game_img)
		ft_exit("Error: cannot load game image");
	if (!w3d->pause_img)
		ft_exit("Error: cannot load pause image");
}

void	put_weapon(t_w3d *w3d)
{
	if (w3d->weap == 2)
		return ;
	if (w3d->weap_state)
		mlx_put_image_to_window(w3d->mlx, w3d->win,
			w3d->weap_imgs[w3d->weap + 2], 350, 372);
	else
		mlx_put_image_to_window(w3d->mlx, w3d->win,
			w3d->weap_imgs[w3d->weap], 350, 372);
}

void	manage_weapon_hook(t_w3d *w3d)
{
	w3d->weap++;
	if (w3d->weap > 2)
		w3d->weap = 0;
	w3d->weap_state = 0;
}

void	enable_shoot(t_w3d *w3d)
{
	if (w3d->weap == 2)
		return ;
	w3d->weap_state = 1;
	w3d->weap_clk = clock();
}

int		manage_shoot_hook(void *param)
{
	t_w3d		*w3d;
	clock_t		clk;

	w3d = (t_w3d*)param;
	clk = clock();
	if (w3d->weap == 2 || w3d->weap_clk == 0)
		return (0);
	if (w3d->weap == 0 && clk < w3d->weap_clk + CLK_TIME_PIST)
		return (0);
	if (w3d->weap == 1 && clk < w3d->weap_clk + CLK_TIME_KNIF)
		return (0);
	w3d->weap_state = 0;
	w3d->weap_clk = 0;
	return (1);
}

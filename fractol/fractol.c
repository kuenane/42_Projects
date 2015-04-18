/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 09:32:39 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/25 16:37:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int				main(int ac, char **av)
{
	t_mlx	*mlx;

	check_ac_and_av(ac, av);
	mlx = give_struct_mlx(av[1][0]);
	set_expose_and_key(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

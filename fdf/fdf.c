/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 10:51:52 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/11 09:44:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int				main(int ac, char **av)
{
	t_mlx	*mlx;

	check_ac_and_av(ac, av);
	mlx = give_struct_mlx(av);
	set_expose_and_key(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

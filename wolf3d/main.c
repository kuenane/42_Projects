/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 09:04:09 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/06 10:59:52 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"
#include <mlx.h>

int		main(int ac, char **av)
{
	t_w3d	w3d;

	if (ac != 2)
		ft_exit("usage: ./wolf3d [filename]");
	init_w3d(&w3d, av[1]);
	set_expose_and_key(&w3d);
	mlx_loop(w3d.mlx);
	return (0);
}

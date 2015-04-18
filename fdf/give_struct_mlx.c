/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_struct_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:43:45 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 17:49:45 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>

static void		*verified_mlx_init(void)
{
	void	*mlx;

	if (!(mlx = mlx_init()))
	{
		ft_putstr_fd("mlx_init error\n", 2);
		exit (EXIT_FAILURE);
	}
	return (mlx);
}

static void		*verified_mlx_new_win(void *mlx)
{
	void	*win;

	if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fdf")))
	{
		ft_putstr_fd("mlx_new_windows error\n", 2);
		exit (EXIT_FAILURE);
	}
	return (win);
}

static void		*verified_new_image(void *mlx)
{
	void	*img;

	if (!(img = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		ft_putstr_fd("mlx_new_image error\n", 2);
		exit (EXIT_FAILURE);
	}
	return (img);
}

t_mlx			*give_struct_mlx(char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)verified_malloc(sizeof(t_mlx) * 1);
	mlx->mlx = verified_mlx_init();
	mlx->win = verified_mlx_new_win(mlx->mlx);
	mlx->img = verified_new_image(mlx->mlx);
	mlx->data = mlx_get_data_addr(mlx->img, &(mlx->octpp), &(mlx->size_line),
								&(mlx->endian));
	mlx->octpp /= 8;
	mlx->tab = give_tab_map(av[1], nb_line(av[1]));
	mlx->x = 0;
	mlx->y = 0;
	mlx->x1 = 0;
	mlx->y1 = 0;
	mlx->x2 = 0;
	mlx->y2 = 0;
	mlx->center = 1500;
	return (mlx);
}

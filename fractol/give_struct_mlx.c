/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_struct_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:43:45 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:10:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
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

static void		*verified_mlx_new_win(void *mlx, char choice)
{
	void	*win;

	if (choice == '1')
		win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol : Mandebrot");
	else if (choice == '2')
		win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol : Julia");
	else if (choice == '3')
		win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol : Douady Rabbit");
	else if (choice == '4')
		win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol : Noun");
	else
		win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol : Chromosom");
	if (!win)
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

static t_mlx	*put_choice(t_mlx *mlx, char choice)
{
	CHOICE = choice;
	CURX = -420;
	CURY = -230;
	if (choice != '1')
	{
		CURX = -(WIDTH / 2);
		CURY = -(HEIGHT / 2);
	}
	return (mlx);
}

t_mlx			*give_struct_mlx(char choice)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)verified_malloc(sizeof(t_mlx) * 1);
	mlx->mlx = verified_mlx_init();
	mlx->win = verified_mlx_new_win(mlx->mlx, choice);
	mlx->img = verified_new_image(mlx->mlx);
	mlx->data = mlx_get_data_addr(mlx->img, &(mlx->octpp), &(mlx->size_line),
								&(mlx->endian));
	mlx->octpp /= 8;
	mlx = put_choice(mlx, choice);
	ZOOM = 200;
	ITER = 150;
	WHICHCOL = 0;
	MSX = 0;
	MSY = 0;
	REDO = 0;
	return (mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 09:44:47 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:12:53 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 560
# define HEIGHT 440
# define LG_DB long double
# define CHOICE mlx->choice
# define CURX mlx->current.x
# define CURY mlx->current.y
# define MSX mlx->mouse.x
# define MSY mlx->mouse.y
# define CR mlx->cri.r
# define CI mlx->cri.i
# define ZR mlx->zri.r
# define ZI mlx->zri.i
# define SQZR mlx->square.r
# define SQZI mlx->square.i
# define ITER mlx->iter
# define WHICHCOL mlx->color
# define ZOOM mlx->zoom
# define REDO mlx->redo

typedef struct	s_coord
{
	long long	x;
	long long	y;
}				t_coord;

typedef struct	s_ri
{
	LG_DB		r;
	LG_DB		i;
}				t_ri;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			octpp;
	int			size_line;
	int			endian;
	char		choice;
	t_coord		current;
	t_coord		mouse;
	t_ri		cri;
	t_ri		zri;
	t_ri		square;
	int			iter;
	int			color;
	LG_DB		zoom;
	char		redo;
}				t_mlx;

void			check_ac_and_av(int ac, char **av);
t_mlx			*give_struct_mlx(char choice);
void			set_expose_and_key(t_mlx *mlx);
void			put_pixel_to_img(t_mlx *mlx, int x, int y, unsigned int color);
int				manage_mouse_move_hook(int x, int y, void *param);
int				manage_mouse_scroll_hook(int button, int x, int y, void *param);
void			mandelbrot(t_mlx *mlx);
void			julia(t_mlx *mlx);
void			put_current_pixel(t_mlx *mlx, t_coord c, int i);
void			col4(t_mlx *mlx, t_coord c, int i);
void			col5(t_mlx *mlx, t_coord c, int i);
void			col6(t_mlx *mlx, t_coord c, int i);
void			col7(t_mlx *mlx, t_coord c, int i);
void			col8(t_mlx *mlx, t_coord c, int i);
void			douady_rabbit(t_mlx *mlx);
void			chromosom(t_mlx *mlx);
void			noun(t_mlx *mlx);

#endif

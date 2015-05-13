/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 09:05:23 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/12 20:24:09 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_H
# define W3D_H

# include <libft.h>
# include <time.h>

# define U_INT unsigned int

/*
** GAME
*/
# define P_HEIGHT 32
# define FOV 60
# define HALF_FOV 30
# define ANGLE_BET_RAY 0.075
# define NB_STAR 10
# define SKY_SPEED 65
# define MV_SPEED 15
# define ROT_SPEED 5
# define CLK_TIME_SKY (CLOCKS_PER_SEC / 8)
# define CLK_TIME_PIST (CLOCKS_PER_SEC / 8)
# define CLK_TIME_KNIF (CLOCKS_PER_SEC / 16)
# define MMAP 5
# define HEIGHT 500.0
# define WIDTH 800.0
# define WIDTH2 1600
# define WIDTH4 3200
# define WIDTH4_50 3250
# define FLOOR_COLOR 0x003D4C

# ifdef __APPLE__

/*
** MAC OS
*/
#  define ESC_KEY 53
#  define RET_KEY 36
#  define SP_KEY 49
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define Q_KEY 12
#  define E_KEY 14
#  define W_KEY 13
#  define A_KEY 0
#  define D_KEY 2
#  define S_KEY 1
#  define P_KEY 35

# else

/*
** LINUX
*/
#  define ESC_KEY 65307
#  define RET_KEY 65293
#  define SP_KEY 32
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define Q_KEY 113
#  define E_KEY 101
#  define W_KEY 119
#  define A_KEY 97
#  define D_KEY 100
#  define S_KEY 115
#  define P_KEY 112

# endif

typedef struct	s_pt
{
	int			x;
	int			y;
}				t_pt;

typedef struct	s_ptdb
{
	double		x;
	double		y;
}				t_ptdb;

typedef struct	s_w3d
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*menu_img;
	void		*game_img;
	void		*pause_img;
	void		**weap_imgs;
	char		*data;
	int			octpp;
	int			size_line;
	int			endian;
	int			**map;
	int			hmap;
	int			wmap;
	t_pt		**sky;
	int			start;
	int			weap;
	int			weap_state;
	clock_t		weap_clk;
	int			pause;
	int			posx;
	int			posy;
	int			ang;
	int			cur_color;
	clock_t		sky_clk;
	int			mapstate;
}				t_w3d;

void			init_player_pos(t_w3d *w3d);
void			init_w3d(t_w3d *w3d, char *av1);
void			load_weapon(t_w3d *w3d);
void			set_expose_and_key(t_w3d *w3d);
void			put_pixel_to_img(t_w3d *w3d, int x, int y, U_INT color);
t_pt			**init_sky(void);
void			put_sky_and_floor(t_w3d *w3d);
void			put_walls(t_w3d *w3d);
void			put_minimap(t_w3d *w3d);
void			put_weapon(t_w3d *w3d);
double			give_littlest(t_w3d *w3d, double ay, double bx, double cur_ray);
void			manage_weapon_hook(t_w3d *w3d);
int				manage_loop_hook(void *param);
int				manage_expose_hook(void *param);
void			move_sky_l_key(t_w3d *w3d);
void			move_sky_r_key(t_w3d *w3d);
void			left_key_pressed(t_w3d *w3d);
void			right_key_pressed(t_w3d *w3d);
void			up_key_pressed(t_w3d *w3d);
void			down_key_pressed(t_w3d *w3d);
void			ft_draw_line_white(t_w3d *w3d, int xsrc, int xdst, int y);
void			ft_draw_line_grey(t_w3d *w3d, int xsrc, int xdst, int y);
void			ft_draw_line_blue(t_w3d *w3d, int xsrc, int xdst, int y);
void			ft_draw_line_green(t_w3d *w3d, int xsrc, int xdst, int y);
int				manage_shoot_hook(void *param);
void			enable_shoot(t_w3d *w3d);

#endif

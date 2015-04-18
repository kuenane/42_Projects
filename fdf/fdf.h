/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 10:51:59 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/14 18:53:27 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 2560
# define HEIGHT 1320
# define UINT unsigned int
# include "mlx_color.h"
# define EOL END_OF_TAB
# define MLX_SIZE 20
# define Z_SIZE 15

/*
** AVAILABLE COLORS : RED-WHITE-GREY-BLUE-PINK-GREEN-BROWN-YELLOW-ORANGE
*/
# define MLX_COLOR MLX_WHITE

typedef struct	s_pt
{
	int			x;
	int			y;
	int			z;
}				t_pt;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			octpp;
	int			size_line;
	int			endian;
	t_pt		**tab;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			center;
}				t_mlx;

void			check_ac_and_av(int ac, char **av);
void			init_errno(void);
void			errno_open_read_close(char *file_name);
int				nb_line(char *file_name);
int				pos_first_digit(char *str);
int				ft_getnbr(char *str, int pos);
int				pos_after_digit(char *str, int pos);
t_pt			**apply_iso_projection(t_pt **tab);
t_pt			**give_tab_map(char *file_name, int nb_line);
t_mlx			*give_struct_mlx(char **av);
void			set_expose_and_key(t_mlx *mlx);
void			put_pixel_to_img(t_mlx *mlx, int x, int y, unsigned int color);
void			put_line_on_img(t_mlx *mlx, t_pt *pt1, t_pt *pt2, UINT color);
void			put_map(t_mlx *mlx, t_pt **tab);
t_pt			**hook_move_map(t_pt **pt, int keycode);

#endif

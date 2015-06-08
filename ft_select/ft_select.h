/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 11:16:29 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 14:51:17 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <termios.h>
# include <term.h>

# define IS_ESC (ikey == 27)
# define IS_SP (ikey == 32)
# define IS_TAB (ikey == 9)
# define IS_DEL (ikey == 2117294875 || ikey == 127)
# define IS_ENT (ikey == 10)
# define IS_TOP_ARROW (ikey == 4283163)
# define IS_BOT_ARROW (ikey == 4348699)
# define IS_RIGHT_ARROW (ikey == 4414235)
# define IS_LEFT_ARROW (ikey == 4479771)
# define COL_ERROR 31
# define COL_DIR 32
# define COL_ARCH 33
# define COL_PDF 35
# define COL_AUTH 36
# define COL_BIN 34
# define COL_OTHER 0
# define DISABLE_OUTPUT tputs(tgetstr("ti", NULL), 1, ft_tputs_tty)
# define ENABLE_OUTPUT tputs(tgetstr("te", NULL), 1, ft_tputs_tty)
# define DISABLE_CURSOR tputs(tgetstr("vi", NULL), 1, ft_tputs_tty)
# define ENABLE_CURSOR tputs(tgetstr("ve", NULL), 1, ft_tputs_tty)
# define ENABLE_UND tputs(tgetstr("us", NULL), 1, ft_tputs_tty)
# define ENABLE_REV tputs(tgetstr("mr", NULL), 1, ft_tputs_tty)
# define DISABLE_ALL tputs(tgetstr("me", NULL), 1, ft_tputs_tty)

typedef struct		s_lst
{
	char			*name;
	t_bool			selected;
	int				color;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	struct termios	termios_save;
	char			*term_name;
	char			*term_buf;
	int				nb_link;
	t_lst			*lst_first;
	t_lst			*lst_cur;
	int				wterm;
	int				hterm;
	t_bool			colors_mode;
	int				len_biggest;
}					t_env;

t_lst				*lst_new_elem(char *name, t_lst *prev);
t_lst				*lst_del_elem(t_env *env, t_lst *elem);
void				init_term(t_env *env);
void				init_env(t_env *env, int ac, char **av);
void				manage_signals(t_env *env);
void				leave_properly(t_env *env, char *ret);
void				clear_the_screen(t_env *env);
void				refresh_term_size(t_env *env);
void				print_lst(t_env *env);
void				manage_keys(t_env *env, int ikey);
void				refresh_len_biggest(t_env *env);
t_lst				*n_inc_lst(t_lst *tmp, int n);
t_lst				*n_dec_lst(t_lst *tmp, int n);

#endif

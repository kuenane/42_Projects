/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 15:40:14 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 15:15:01 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TAB :
** [0] %
** [1] -
** [2] +
** [3] #
** [4] 0
** [5] space
** [6] width_min
** [7] preci
** [8] length h
** [9] length j
** [10] length l
** [11] length z
** [12] convert
** [13] current option len
** [14] error
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define SP_SP "  "
# define Z_Z "00"

int		ft_printf(const char *format, ...);
void	current_option_put_tab(char *s, int *tab);
int		*current_option_len(char *s, int *tab);
void	current_option_put12345(char *s, int *tab, int i);
int		print_current_option(int *tab, va_list ap, char c);
char	*apply_preci_min(char *str, int *tab);
char	*apply_width_min(char *str, int *tab);
int		option_4242(int *tab, char c);
int		option_b(int *tab, va_list ap);
int		option_c(int *tab, va_list ap);
int		option_d(int *tab, va_list ap);
int		option_o(int *tab, va_list ap);
int		option_p(int *tab, va_list ap);
int		option_percent(int *tab);
int		option_s(int *tab, va_list ap);
int		option_u(int *tab, va_list ap);
int		option_x(int *tab, va_list ap);

#endif

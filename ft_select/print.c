/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 20:39:43 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 14:59:41 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <fcntl.h>
#include <unistd.h>

#define WCELL (env->len_biggest + 4)
#define NB_PER_COL (env->wterm / WCELL)
#define TOTAL_POSSIBILTY (NB_PER_COL * env->hterm)
#define ESTIMATED_LINE div_and_arr(env->nb_link, NB_PER_COL)
#define LMARGIN ft_putnchar_fd(' ', 2, fd)
#define RMARGIN ft_putnchar_fd(' ', env->len_biggest+2-ft_strlen(tmp->name), fd)

static void		print_one_elem(t_env *env, t_lst *tmp, int fd)
{
	LMARGIN;
	if (tmp->selected)
		ENABLE_REV;
	if (env->lst_cur == tmp)
		ENABLE_UND;
	if (!tmp->color || !env->colors_mode)
		ft_putstr_fd(tmp->name, fd);
	else
		ft_putstr_col_fd(tmp->name, tmp->color, fd);
	DISABLE_ALL;
	RMARGIN;
}

static void		print_line(t_env *env, t_lst *tmp, int fd, int *nb)
{
	int		nb_to_print;

	nb_to_print = NB_PER_COL;
	while (nb_to_print > 0 && *nb > 0)
	{
		print_one_elem(env, tmp, fd);
		tmp = tmp->next;
		nb_to_print--;
		*nb = *nb - 1;
	}
	ft_putchar_fd('\n', fd);
}

void			print_lst(t_env *env)
{
	int		fd;
	int		nb;
	t_lst	*tmp;

	if ((fd = open("/dev/tty", O_WRONLY)) == -1)
		leave_properly(env, NULL);
	refresh_len_biggest(env);
	nb = env->nb_link;
	tmp = env->lst_first;
	clear_the_screen(env);
	if (NB_PER_COL < 1 || TOTAL_POSSIBILTY < env->nb_link)
	{
		ft_putstr_fd("Window too small", fd);
		return ;
	}
	while (nb > 0)
	{
		print_line(env, tmp, fd, &nb);
		tmp = n_inc_lst(tmp, NB_PER_COL);
	}
	if (close(fd))
		leave_properly(env, NULL);
}

void			refresh_len_biggest(t_env *env)
{
	int		nb;
	t_lst	*tmp;
	int		curlen;

	nb = env->nb_link + 1;
	tmp = env->lst_first;
	env->len_biggest = 0;
	while (--nb > 0)
	{
		curlen = ft_strlen(tmp->name);
		if (curlen > env->len_biggest)
			env->len_biggest = curlen;
		tmp = tmp->next;
	}
}

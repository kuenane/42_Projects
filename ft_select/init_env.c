/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:34:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 08:47:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>
#include <fcntl.h>

static t_lst	*build_list(int nb, char **args)
{
	t_lst	*lst;
	t_lst	*first;
	int		i;

	if (!nb)
		ft_exit(NULL);
	lst = lst_new_elem(args[0], NULL);
	first = lst;
	i = 1;
	while (i < nb)
	{
		lst->next = lst_new_elem(args[i], lst);
		lst = lst->next;
		i++;
	}
	lst->next = first;
	first->prev = lst;
	return (first);
}

void			init_term(t_env *env)
{
	struct termios	tmp;

	DISABLE_OUTPUT;
	DISABLE_CURSOR;
	if (tcgetattr(0, &env->termios_save))
		ft_exit("error: Cannot get termios struct");
	tmp = env->termios_save;
	tmp.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL);
	tmp.c_cc[VMIN] = 1;
	tmp.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &tmp))
		ft_exit("error: Cannot set termios struct");
	refresh_term_size(env);
}

void			init_env(t_env *env, int ac, char **av)
{
	ft_bzero(env, sizeof(t_env));
	if (!(env->term_name = getenv("TERM")))
		ft_exit("error: TERM is not set in environment");
	env->term_buf = v_malloc(sizeof(char) * 2048);
	if (tgetent(env->term_buf, env->term_name) <= 0)
		ft_exit("error: Cannot access the termcap database");
	env->nb_link = ac - 1;
	env->lst_first = build_list(ac - 1, &av[1]);
	env->lst_cur = env->lst_first;
	init_term(env);
}

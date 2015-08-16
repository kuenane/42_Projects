/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 06:14:46 by dw31              #+#    #+#             */
/*   Updated: 2015/08/16 09:34:39 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define POS_LAST_ANT ANT(NB_ANTS - 1)->pos

static void		print_statement(t_env *env, int id)
{
	int		i;

	i = 0;
	ft_putchar('L');
	ft_putnbr(id + 1);
	ft_putchar('-');
	while (ANT(id)->pos != ROOM(i)->id)
		i++;
	ft_putstr(ROOM(i)->name);
}

static int		pos_front_ant(t_env *env)
{
	int		i;

	i = 0;
	while (i < NB_ANTS)
	{
		if (ANT(i)->pos != END_ROOM)
			return (i);
		i++;
	}
	return (2147483647);
}

static int		pos_back_ant(t_env *env)
{
	int		i;

	i = 0;
	while (i < NB_ANTS)
	{
		if (ANT(i)->pos == START_ROOM)
			return (i);
		i++;
	}
	return (NB_ANTS - 1);
}

static void		send_a_wave(t_env *env, int cur_ant, int last, int cur_pos)
{
	t_bool	isfirst;

	isfirst = TRUE;
	while (cur_ant <= last)
	{
		ANT(cur_ant)->pos = LIT_PATH(cur_pos + 1);
		if (isfirst)
			isfirst = FALSE;
		else
			ft_putchar(' ');
		print_statement(env, cur_ant);
		cur_ant++;
		cur_pos--;
	}
	ft_putchar('\n');
}

void			send_ants(t_env *env)
{
	int		pos_front;
	int		pos_back;
	int		pos_front_tsearch;

	if (SIZE_LIT_PATH <= 0 || SIZE_LIT_PATH == 2147483647)
		ft_exit(ERR_MSG);
	while (POS_LAST_ANT != END_ROOM)
	{
		pos_front = pos_front_ant(env);
		pos_back = pos_back_ant(env);
		pos_front_tsearch = 0;
		while (ANT(pos_front)->pos != LIT_PATH(pos_front_tsearch))
			pos_front_tsearch++;
		send_a_wave(env, pos_front, pos_back, pos_front_tsearch);
	}
}

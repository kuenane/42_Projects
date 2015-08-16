/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 16:14:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/16 09:35:58 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_input_save(char **input_save)
{
	int		i;

	i = -1;
	while (input_save[++i])
		ft_free(input_save[i]);
	ft_free(input_save);
	ft_putchar('\n');
}

static void		check_if_everythink_ok(t_env *env)
{
	if (NB_ANTS <= 0 || NB_ROOMS <= 0 || START_ROOM == -1 || END_ROOM == -1
		|| START_ROOM == END_ROOM)
		ft_exit(ERR_MSG);
}

static void		print_start_debug(t_env *env)
{
	int		i;

	if (!DEBUG_MODE)
		return ;
	ft_putendl_col(DEB_START_MSG, 32);
	i = -1;
	ft_putstr("NB_ROOMS = ");
	ft_putnbr(NB_ROOMS);
	ft_putstr("\nROOMS = ");
	while (++i < NB_ROOMS)
	{
		ft_putstr(ROOM(i)->name);
		ft_putstr(" ");
	}
	ft_putchar('\n');
}

static void		print_end_debug(t_env *env)
{
	int		i;

	if (!DEBUG_MODE)
		return ;
	i = -1;
	ft_putstr("SIZE_LIT_PATH = ");
	ft_putnbr(SIZE_LIT_PATH);
	ft_putstr("\nLIT_PATH =");
	while (++i < SIZE_LIT_PATH && SIZE_LIT_PATH != 2147483647)
	{
		ft_putchar(' ');
		ft_putnbr(LIT_PATH(i));
	}
	ft_putchar('\n');
	ft_putendl_col(DEB_END_MSG, 32);
}

int				main(void)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	init_env(&env);
	check_if_everythink_ok(&env);
	print_start_debug(&env);
	put_lit_path(&env);
	print_end_debug(&env);
	ft_putstrtab(env.input_save, "\n", "\n");
	free_input_save(env.input_save);
	send_ants(&env);
	return (0);
}

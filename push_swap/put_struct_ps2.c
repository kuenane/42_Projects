/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_struct_ps2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 11:25:17 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 08:34:50 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_for_duplicates(int *save_real, int ac, int i, int nb)
{
	while (ac > 1)
	{
		if ((ac - 1) != i && save_real[ac - 1] == nb)
			ft_exit("Error");
		ac--;
	}
}

static int		give_simple_nb(int *save_real, int ac, int i)
{
	int		nb;
	int		j;

	nb = 1;
	j = 0;
	while (j != ac)
		if (save_real[j++] < save_real[i])
			nb++;
	return (nb);
}

static void		solve_the_solved_tab(t_ps *ps, int ac)
{
	int		i;

	i = -1;
	while (++i < ac)
		ps->solved[i] = i + 1;
}

void			put_a_b_solved(t_ps *ps, int ac)
{
	int		i;

	ps->a = (int*)v_malloc(sizeof(int) * (ac));
	ps->b = (int*)v_malloc(sizeof(int) * (ac));
	ps->save_new = (int*)v_malloc(sizeof(int) * (ac));
	ps->solved = (int*)v_malloc(sizeof(int) * (ac));
	i = 0;
	while (i < ac)
	{
		check_for_duplicates(ps->save_real, ac, i, ps->save_real[i]);
		ps->save_new[i] = give_simple_nb(ps->save_real, ac, i);
		ps->a[i] = give_simple_nb(ps->save_real, ac, i);
		ps->b[i] = 0;
		i++;
	}
	solve_the_solved_tab(ps, ac);
}

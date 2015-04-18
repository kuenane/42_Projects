/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_algo_smartsort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:26:24 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 20:09:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_push_b_a(t_ps *ps, int ac)
{
	while (ps->b[0])
	{
		action_pa(ps->a, ps->b, ac);
		ft_putstr("pa ");
		if (ps->v)
			verbose_enabled(ps, ps->a, ps->b, ac);
	}
}

static void		sa_with_modif(t_ps *ps, int ac)
{
	action_sa(ps->a);
	ft_putstr("sa ");
	if (ps->v)
		verbose_enabled(ps, ps->a, ps->b, ac);
}

static void		pb_with_modif(t_ps *ps, int ac, int *len)
{
	action_pb(ps->a, ps->b, ac);
	(*len)--;
	ft_putstr("pb ");
	if (ps->v)
		verbose_enabled(ps, ps->a, ps->b, ac);
}

static void		rra_with_modif(t_ps *ps, int ac)
{
	action_rra(ps->a, ac);
	ft_putstr("rra ");
	if (ps->v)
		verbose_enabled(ps, ps->a, ps->b, ac);
}

void			print_smartsort(t_ps *ps, int ac, int len, int smpos)
{
	if (ps->a[1])
	{
		while (ps->a[1] && check_if_solved(ps->a, ps->solved, len))
		{
			smpos = smaller_pos(ps->a, len);
			if (smpos == len - 1 || smpos > len / 2)
				rra_with_modif(ps, ac);
			else if (!smpos)
				pb_with_modif(ps, ac, &len);
			else if (smpos == 1)
				sa_with_modif(ps, ac);
			else
			{
				action_ra(ps->a, ac);
				ft_putstr("ra ");
				if (ps->v)
					verbose_enabled(ps, ps->a, ps->b, ac);
			}
		}
	}
	print_push_b_a(ps, ac);
	ft_putchar('\n');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_smartsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:28:03 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 20:09:18 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sa_with_modif(t_ps *ps, t_alg *alg)
{
	action_sa(ps->a);
	alg->act = add_str_strtab(alg->act, "sa");
}

static void		pb_with_modif(t_ps *ps, t_alg *alg, int ac, int *len)
{
	action_pb(ps->a, ps->b, ac);
	(*len)--;
	alg->act = add_str_strtab(alg->act, "pb");
}

static void		rra_with_modif(t_ps *ps, t_alg *alg, int ac)
{
	action_rra(ps->a, ac);
	alg->act = add_str_strtab(alg->act, "rra");
}

void			put_algo_smartsort(t_alg *alg, t_ps *ps, int ac, int len)
{
	int		smpos;

	if (ps->a[1])
	{
		while (ps->a[1] && check_if_solved(ps->a, ps->solved, len))
		{
			smpos = smaller_pos(ps->a, len);
			if (smpos == len - 1 || smpos > len / 2)
				rra_with_modif(ps, alg, ac);
			else if (!smpos)
				pb_with_modif(ps, alg, ac, &len);
			else if (smpos == 1)
				sa_with_modif(ps, alg);
			else
			{
				action_ra(ps->a, ac);
				alg->act = add_str_strtab(alg->act, "ra");
			}
			alg->nb++;
		}
	}
	push_b_to_a(ps, alg, ac);
}

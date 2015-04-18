/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bruteforce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:27:32 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 17:38:37 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_algo_bruteforce(t_alg *alg, t_ps *ps, int ac)
{
	if (ps->a[1])
	{
		while (ps->a[1])
		{
			if (!smaller_pos(ps->a, len_stack(ps->a, ac)))
			{
				action_pb(ps->a, ps->b, ac);
				alg->act = add_str_strtab(alg->act, "pb");
			}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_various.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:50:45 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 19:32:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_algo_various1(t_alg *alg, t_ps *ps, int ac, int i)
{
	while (++i <= 40 && check_if_solved(ps->a, ps->solved, ac))
	{
		if (i == 3)
		{
			action_sa(ps->a);
			alg->act = add_str_strtab(alg->act, "sa");
		}
		else
		{
			action_rra(ps->a, ac);
			alg->act = add_str_strtab(alg->act, "rra");
		}
		alg->nb++;
	}
	if (i == 40)
		alg->nb = 999999;
}

void		put_algo_various2(t_alg *alg, t_ps *ps, int ac, int i)
{
	while (++i <= 40 && check_if_solved(ps->a, ps->solved, ac))
	{
		if (i % 2 != 0)
		{
			action_ra(ps->a, ac);
			alg->act = add_str_strtab(alg->act, "ra");
		}
		else
		{
			action_sa(ps->a);
			alg->act = add_str_strtab(alg->act, "sa");
		}
		alg->nb++;
	}
	if (i == 40)
		alg->nb = 999999;
}

void		put_algo_various3(t_alg *alg, t_ps *ps, int ac, int i)
{
	while (++i <= 40 && check_if_solved(ps->a, ps->solved, ac))
	{
		action_ra(ps->a, ac);
		alg->act = add_str_strtab(alg->act, "ra");
		alg->nb++;
	}
	if (i == 40)
		alg->nb = 999999;
}

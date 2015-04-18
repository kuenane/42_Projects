/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 14:47:06 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 17:30:54 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy_stack(int *src, int *dst, int ac)
{
	while (--ac)
		dst[ac] = src[ac];
}

void	restore_a_b_stack(t_ps *ps, int ac)
{
	while (--ac >= 0)
	{
		ps->a[ac] = ps->save_new[ac];
		ps->b[ac] = 0;
	}
}

int		len_stack(int *stack, int ac)
{
	int		i;

	i = 0;
	while (i < ac && stack[i])
		i++;
	return (i);
}

int		smaller_pos(int *stack, int len)
{
	int		i;
	int		pos;
	int		min;

	i = 0;
	pos = 0;
	min = stack[pos];
	while (i < len)
	{
		if (stack[i] < min)
		{
			pos = i;
			min = stack[pos];
		}
		i++;
	}
	return (pos);
}

void	push_b_to_a(t_ps *ps, t_alg *alg, int ac)
{
	while (ps->b[0])
	{
		action_pa(ps->a, ps->b, ac);
		alg->act = add_str_strtab(alg->act, "pa");
		alg->nb++;
	}
}

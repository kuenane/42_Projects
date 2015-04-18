/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rra_rrb_rrr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:26:01 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 11:49:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		give_bot_stack(int *stack, int ac)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		if (!stack[i])
			return (stack[i - 1]);
		i++;
	}
	return (stack[ac - 1]);
}

static void		put_bot_stack_zero(int *stack, int ac)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		if (!stack[i])
		{
			stack[i - 1] = 0;
			return ;
		}
		i++;
	}
	stack[ac - 1] = 0;
}

void			action_rra(int *a, int ac)
{
	int		tmp;

	if (a[0] && a[1])
	{
		tmp = give_bot_stack(a, ac);
		put_bot_stack_zero(a, ac);
		desc_the_stack(a, ac);
		a[0] = tmp;
	}
}

void			action_rrb(int *b, int ac)
{
	int		tmp;

	if (b[0] && b[1])
	{
		tmp = give_bot_stack(b, ac);
		put_bot_stack_zero(b, ac);
		desc_the_stack(b, ac);
		b[0] = tmp;
	}
}

void			action_rrr(int *a, int *b, int ac)
{
	action_rra(a, ac);
	action_rrb(b, ac);
}

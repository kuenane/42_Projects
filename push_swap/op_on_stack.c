/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:40:59 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 12:01:41 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_it_on_top(int *stack, int nb, int ac)
{
	if (!stack[0])
	{
		stack[0] = nb;
		return ;
	}
	ac -= 2;
	while (ac)
	{
		swap_two_int(&stack[ac + 1], &stack[ac]);
		ac--;
	}
	stack[0] = nb;
}

void	put_it_on_bot(int *stack, int nb)
{
	int		i;

	i = 0;
	while (stack[i])
		i++;
	stack[i] = nb;
}

void	del_the_top(int *stack, int ac)
{
	int		i;

	i = 0;
	stack[0] = 0;
	while (++i < ac)
		swap_two_int(&stack[i - 1], &stack[i]);
}

void	desc_the_stack(int *stack, int ac)
{
	while (--ac)
		swap_two_int(&stack[ac], &stack[ac - 1]);
}

void	print_stack(int *stack, int ac)
{
	int		i;

	i = 0;
	while (i < ac && stack[i])
	{
		ft_putnbr(stack[i]);
		if (i < ac - 1 && stack[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

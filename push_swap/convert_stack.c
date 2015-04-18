/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:48:20 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 11:57:12 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	give_corresponding(t_ps *ps, int nb, int ac)
{
	ac--;
	while (ps->save_new[ac] != nb)
		ac--;
	return (ps->save_real[ac]);
}

int			*convert_stack(t_ps *ps, int *to_convert, int ac)
{
	int		*converted;
	int		i;

	i = -1;
	converted = (int*)v_malloc(sizeof(int) * (ac));
	while (++i < ac)
		converted[i] = give_corresponding(ps, to_convert[i], ac);
	return (converted);
}

void		print_converted_stack(t_ps *ps, int *stack, int ac)
{
	int		i;

	i = 0;
	while (i < ac && stack[i])
	{
		ft_putnbr(give_corresponding(ps, stack[i], ac));
		if (i < ac - 1 && stack[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

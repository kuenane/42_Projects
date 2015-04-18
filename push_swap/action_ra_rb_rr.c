/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra_rb_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:25:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 11:29:18 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_ra(int *a, int ac)
{
	int		tmp;

	if (a[0])
	{
		tmp = a[0];
		del_the_top(a, ac);
		put_it_on_bot(a, tmp);
	}
}

void	action_rb(int *b, int ac)
{
	int		tmp;

	if (b[0])
	{
		tmp = b[0];
		del_the_top(b, ac);
		put_it_on_bot(b, tmp);
	}
}

void	action_rr(int *a, int *b, int ac)
{
	action_ra(a, ac);
	action_rb(b, ac);
}

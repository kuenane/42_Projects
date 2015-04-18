/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:36:58 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 11:46:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_pa(int *a, int *b, int ac)
{
	if (b[0])
	{
		if (a[0])
			desc_the_stack(a, ac);
		put_it_on_top(a, b[0], ac);
		del_the_top(b, ac);
	}
}

void	action_pb(int *a, int *b, int ac)
{
	if (a[0])
	{
		if (b[0])
			desc_the_stack(b, ac);
		put_it_on_top(b, a[0], ac);
		del_the_top(a, ac);
	}
}

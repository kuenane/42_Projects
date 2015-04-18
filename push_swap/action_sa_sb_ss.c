/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa_sb_ss.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:10:31 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 11:24:04 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_sa(int *a)
{
	if (a[0] && a[1])
		swap_two_int(&a[0], &a[1]);
}

void	action_sb(int *b)
{
	if (b[0] && b[1])
		swap_two_int(&b[0], &b[1]);
}

void	action_ss(int *a, int *b)
{
	action_sa(a);
	action_sb(b);
}

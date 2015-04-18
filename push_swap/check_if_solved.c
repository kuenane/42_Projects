/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_solved.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:50:50 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 11:56:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if_solved(int *a, int *solved, int ac)
{
	int		i;

	if (!a[ac - 1])
		return (-1);
	i = -1;
	while (++i < ac)
		if (a[i] != solved[i])
			return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 19:38:00 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 19:54:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verbose_enabled(t_ps *ps, int *a, int *b, int ac)
{
	ft_putstr("\na: ");
	print_converted_stack(ps, a, ac);
	ft_putstr("b: ");
	print_converted_stack(ps, b, ac);
	ft_putchar('\n');
}

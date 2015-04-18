/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:40:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 13:21:13 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_ps	ps;

	put_struct_ps(&ac, av, &ps);
	if (ps.i)
		interactive_mode(&ps, ac);
	else
		normal_mode(&ps, ac);
	return (0);
}

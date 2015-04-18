/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errno_av_ac.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 14:45:29 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:13:49 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <stdlib.h>

void	check_ac_and_av(int ac, char **av)
{
	if (ac != 2 || av[1][0] < '1' || av[1][0] > '5')
	{
		ft_putendl_fd("usage : ./fractol 1/2/3/4/5", 2);
		ft_putstr_fd("1-Mandelbrot 2-Julia 3-Douady Rabbit ", 2);
		ft_putendl_fd("4-Noun 5-Chromosom", 2);
		exit(EXIT_FAILURE);
	}
}

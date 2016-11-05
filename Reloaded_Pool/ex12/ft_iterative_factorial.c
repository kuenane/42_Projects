/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:25:20 by wide-aze          #+#    #+#             */
/*   Updated: 2016/11/05 16:11:59 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		total;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	total = nb;
	while (--nb)
		total *= nb;
	return (total);
}

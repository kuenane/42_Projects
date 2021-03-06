/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/14 13:16:29 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 15:49:03 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(int n)
{
	char	*tmp;

	tmp = ft_itoa(n);
	ft_putstr(tmp);
	ft_free(tmp);
}

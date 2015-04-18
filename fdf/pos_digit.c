/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:36:48 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/16 10:41:05 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int		pos_first_digit(char *str)
{
	int		pos;

	pos = 0;
	while (str[pos] < '0' || str[pos] > '9')
	{
		if (!str[pos])
		{
			ft_putstr_fd("error : void map\n", 2);
			exit(EXIT_FAILURE);
		}
		pos++;
	}
	return (pos);
}

int		pos_after_digit(char *str, int pos)
{
	while (str[pos] >= '0' && str[pos] <= '9')
		pos++;
	return (pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:49:38 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/28 10:25:50 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int		bdin_exit(char *signal)
{
	ft_putendl("exit");
	if (signal)
		exit(ft_atoi(signal));
	exit(0);
	return (0);
}

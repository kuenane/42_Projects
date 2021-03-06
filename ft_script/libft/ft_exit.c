/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:40:15 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/22 15:36:23 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_exit(char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

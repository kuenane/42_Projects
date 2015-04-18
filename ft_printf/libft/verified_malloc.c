/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 08:33:32 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/31 08:35:05 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*verified_malloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new || size == 0)
	{
		ft_putendl_fd("Malloc error", 2);
		exit(EXIT_FAILURE);
	}
	return (new);
}

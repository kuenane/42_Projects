/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:57:42 by wide-aze          #+#    #+#             */
/*   Updated: 2016/08/02 23:50:20 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = malloc(size);
	if (!s)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}

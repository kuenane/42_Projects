/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:57:51 by wide-aze          #+#    #+#             */
/*   Updated: 2016/08/02 23:49:24 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_cpy;
	const char	*src_cpy;

	i = -1;
	dst_cpy = dst;
	src_cpy = src;
	while (++i != n)
		dst_cpy[i] = src_cpy[i];
	return (dst);
}

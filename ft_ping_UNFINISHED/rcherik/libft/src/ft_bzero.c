/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:38:40 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
		str[i++] = 0;
}

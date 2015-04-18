/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:49:32 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/09 11:42:42 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_char;
	void	*s_return;

	i = 0;
	s_char = (char*)s;
	while (i != n)
	{
		if (s_char[i] == (char)c)
		{
			s_return = &s_char[i];
			return (s_return);
		}
		i++;
	}
	return (NULL);
}

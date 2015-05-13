/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 15:52:11 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/05 15:57:29 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define MIN_INT_STR "-2147483648"
#define MAX_INT_STR	"2147483647"

int		ft_str_isint(const char *s)
{
	int				len;

	len = (*s == '-') ? 1 : 0;
	while (ft_isdigit(s[len]))
		len++;
	if (s[len] != '\0' || (len == 1 && *s == '-'))
		return (0);
	if (*s == '-' && len == 11 && ft_memcmp(s, MIN_INT_STR, 11) > 0)
		return (0);
	if (*s != '-' && len == 10 && ft_memcmp(s, MAX_INT_STR, 10) > 0)
		return (0);
	if (len > 10)
		return (0);
	return (1);
}

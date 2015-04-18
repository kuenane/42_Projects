/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:46:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 17:13:17 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_strtabnew(size_t size)
{
	char	**new;

	if (size == (size_t)-1)
		return (NULL);
	if (!(new = (char**)ft_malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	ft_bzero(new, sizeof(char*) * (size + 1));
	return (new);
}

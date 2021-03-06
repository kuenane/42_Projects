/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:09:22 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/05 15:14:18 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub_free(char *str, int start, size_t len)
{
	char	*new;

	if (!(new = ft_strnew(len)))
		return (NULL);
	new = ft_strncpy(new, &str[start], len);
	free(str);
	return (new);
}

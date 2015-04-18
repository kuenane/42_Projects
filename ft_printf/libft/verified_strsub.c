/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified_strsub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 08:35:53 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/31 08:36:13 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*verified_strsub(char *str, unsigned int start, size_t len)
{
	char	*new;

	if (!str)
		return (NULL);
	new = verified_strnew(len);
	return (ft_strncat(new, str + start, len));
}

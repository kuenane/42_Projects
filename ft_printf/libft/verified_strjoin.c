/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 08:36:24 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/31 08:36:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*verified_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = verified_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	new = ft_strcpy(new, s1);
	return (ft_strcat(new, s2));
}

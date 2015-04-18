/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 08:35:16 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/31 08:35:38 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*verified_strdup(char *str)
{
	char	*new;

	new = verified_strnew(ft_strlen(str));
	return (ft_strcat(new, str));
}

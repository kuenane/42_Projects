/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified_strsub_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:00:07 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/17 13:00:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*verified_strsub_free(char *str, int pos)
{
	char	*new;

	new = verified_strsub(str, pos, ft_strlen(str));
	free(str);
	return (new);
}

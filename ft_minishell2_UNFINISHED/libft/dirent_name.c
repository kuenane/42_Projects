/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirent_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:20:48 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/22 10:26:06 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

char	*dirent_to_str(char *str, int len)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (len + 1));
	new = ft_memcpy((void*)new, (void*)str, len);
	new[len] = '\0';
	return (new);
}

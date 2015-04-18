/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified_strnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 08:34:11 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/31 08:34:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*verified_strnew(size_t size)
{
	char	*new;

	size++;
	new = verified_malloc(size);
	ft_bzero((void*)new, size);
	return (new);
}

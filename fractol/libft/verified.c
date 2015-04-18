/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 08:31:45 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/05 11:09:23 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*verified_malloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new || size == 0)
	{
		ft_putendl_fd("Malloc error", 2);
		exit(EXIT_FAILURE);
	}
	return (new);
}

char	*verified_strnew(size_t size)
{
	char	*new;

	size++;
	new = verified_malloc(size);
	ft_bzero((void*)new, size);
	return (new);
}

char	*verified_strdup(char *str)
{
	char	*new;

	new = verified_strnew(ft_strlen(str));
	return (ft_strcat(new, str));
}

char	*verified_strsub(char *str, unsigned int start, size_t len)
{
	char	*new;

	if (!str)
		return (NULL);
	new = verified_strnew(len);
	return (ft_strncat(new, str + start, len));
}

char	*verified_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = verified_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	new = ft_strcpy(new, s1);
	return (ft_strcat(new, s2));
}

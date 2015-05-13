/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:18:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/31 08:18:43 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	**add_str_strtab(char **tab, char *str)
{
	char	**new;
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	if (!(new = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free(tab);
	return (new);
}

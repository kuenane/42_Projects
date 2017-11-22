/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 07:29:39 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/30 10:05:11 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	**add_str_to_tab(char **tab, char *str)
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

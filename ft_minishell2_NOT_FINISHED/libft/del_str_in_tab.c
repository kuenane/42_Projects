/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 10:33:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 11:51:49 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	del_str_in_tab(char **tab, char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (ft_strncmp(tab[i], str, len))
		i++;
	i++;
	while (tab[i])
	{
		tab[i - 1] = tab[i];
		i++;
	}
	tab[i - 1] = NULL;
}

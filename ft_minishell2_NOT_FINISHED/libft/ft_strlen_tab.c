/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 07:36:22 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/23 18:25:43 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_tab(char **tab)
{
	int		i;

	if (!tab || !tab[0])
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

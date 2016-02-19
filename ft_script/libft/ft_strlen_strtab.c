/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_strtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:21:48 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/31 08:21:53 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_strtab(char **tab)
{
	int		i;

	if (!tab || !tab[0])
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
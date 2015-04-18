/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 10:17:40 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 13:37:09 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_read		*a_option(t_read *list, int a_option)
{
	t_read		*current;

	current = list;
	while (current && (!a_option))
	{
		if (current->name[0] == '.')
		{
			list = (*remove_elem(&list, current->name));
			current = list;
		}
		else
			current = current->next;
	}
	return (list);
}

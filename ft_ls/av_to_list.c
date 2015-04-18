/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_to_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:01:09 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 13:49:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

static int		index_first_arg(int ac, char **av)
{
	int		i;

	i = 1;
	while (av[i] && av[i][0] == '-' && av[i][1] && ft_strcmp(av[i], "--"))
		i++;
	if (i < ac && !(ft_strcmp(av[i], "--")))
		i++;
	if (i == ac)
		return (0);
	return (i);
}

t_read			*give_arg(int ac, char **av)
{
	t_read		*arg;
	int			i;

	if (!(i = index_first_arg(ac, av)))
		return (NULL);
	arg = NULL;
	while (i < ac)
	{
		arg = add_elem(arg, av[i]);
		i++;
	}
	return (arg);
}

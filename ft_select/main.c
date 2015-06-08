/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 11:13:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/06 22:41:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	t_env	env;
	char	key[4];
	int		ikey;

	init_env(&env, ac, av);
	manage_signals(&env);
	print_lst(&env);
	while (42)
	{
		ft_bzero(&key, sizeof(key));
		read(0, key, 4);
		ikey = *(int*)&key[0];
		manage_keys(&env, ikey);
		print_lst(&env);
	}
	return (0);
}

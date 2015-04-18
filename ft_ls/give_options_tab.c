/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_options_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 10:14:15 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 14:16:09 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

static void		put_error_illegal_option(char *prog_name, char c)
{
	if (prog_name[0] == '.' && prog_name[1] == '/')
		ft_putstr_fd(&(prog_name[2]), 2);
	else
		ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(" : illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ft_ls [-Ralrt] [file ...]", 2);
}

static void		init_options_tab(int *options)
{
	options[0] = 0;
	options[1] = 0;
	options[2] = 0;
	options[3] = 0;
	options[4] = 0;
}

static int		check_char(char c)
{
	if (c == 'R')
		return (0);
	if (c == 'a')
		return (1);
	if (c == 'l')
		return (2);
	if (c == 'r')
		return (3);
	if (c == 't')
		return (4);
	return (42);
}

static char		is_an_option(char *av, int *options)
{
	int		i;
	char	c;

	i = 1;
	while (av[i])
	{
		c = av[i];
		if (check_char(c) == 42)
			return (c);
		else
			options[check_char(c)]++;
		i++;
	}
	return ('\0');
}

int				put_options_tab(char **av, int *options)
{
	int		i;
	char	ret;

	i = 1;
	init_options_tab(options);
	while (av[i] && av[i][0] == '-' && av[i][1] && ft_strcmp(av[i], "--") != 0)
	{
		if ((ret = is_an_option(av[i], options)) != '\0')
		{
			put_error_illegal_option(av[0], ret);
			return (-1);
		}
		i++;
	}
	return (0);
}

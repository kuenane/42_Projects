/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errno_av_ac.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 14:45:29 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/18 17:07:43 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <stdlib.h>

void	check_ac_and_av(int ac, char **av)
{
	int		len;

	if (ac == 1)
	{
		ft_putstr_fd("usage : ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(" file1\n", 2);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(av[1]);
	if (av[1][--len] != 'f' || av[1][--len] != 'd' ||
		av[1][--len] != 'f' || av[1][--len] != '.')
	{
		ft_putstr_fd("error : file extension must be .fdf\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	init_errno(void)
{
	errno = 0;
}

void	errno_open_read_close(char *file_name)
{
	if (errno)
	{
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit (EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:33:59 by wide-aze          #+#    #+#             */
/*   Updated: 2016/11/05 15:43:00 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 32768

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(av[1], O_RDONLY);
		if ((ret = read(fd, buf, BUF_SIZE)) > 0)
			write(1, buf, ret);
		close(fd);
	}
}

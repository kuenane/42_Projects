/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs_tty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 20:24:19 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/07 17:13:24 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_tputs_tty(int c)
{
	int		fd;

	fd = open("/dev/tty", O_WRONLY);
	write(fd, &c, 1);
	close(fd);
	return (0);
}

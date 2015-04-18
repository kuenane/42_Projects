/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 09:04:10 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/19 10:26:44 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# define EOF (-1)
# define BUF_SIZE 100
# define GBUF (gnl->buf)
# define GI (gnl->i)

typedef struct	s_gnl_list
{
	char		buf[BUF_SIZE + 1];
	int			fd_save;
	int			i;
}				t_gnl_list;

int				get_next_line(int const fd, char **line);

#endif

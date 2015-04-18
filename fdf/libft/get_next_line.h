/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 09:01:21 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/15 09:01:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct			s_readi
{
	char				s[BUFF_SIZE];
	int					read;
	int					start;
	int					end;
	struct s_readi		*next;
}						t_readi;

typedef struct			s_file_d
{
	int					fd;
	t_readi				**firstcall;
	struct s_file_d		*next;
}						t_file_d;

#endif

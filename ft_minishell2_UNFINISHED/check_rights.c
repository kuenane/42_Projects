/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:36:45 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/22 16:00:57 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <sys/stat.h>
#include <unistd.h>

int		check_file_rights(char *path)
{
	struct stat		l_s;

	if (lstat(path, &l_s) < 0)
		return (print_error_lstat(path, 1), 1);
	if (S_ISDIR(l_s.st_mode))
		return (print_error_lstat(path, 2), 1);
	if (!(l_s.st_mode & (1 << (9 - 3))))
		return (print_error_lstat(path, 3), 1);
	return (0);
}

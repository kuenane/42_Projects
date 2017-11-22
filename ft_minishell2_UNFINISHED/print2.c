/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 08:43:41 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 18:49:00 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_error_path_access(char *cmd, int error)
{
	ft_putstr_fd("ft_minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (error == -1)
		ft_putendl_fd(": No such file or directory", 2);
	else if (error == -2)
		ft_putendl_fd(" Not a directory", 2);
	else
		ft_putendl_fd(": Permission denied", 2);
}

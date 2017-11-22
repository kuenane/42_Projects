/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:53:37 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/28 16:49:40 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_error_bad_cmd(char *cmd, int ret)
{
	if (cmd && cmd[0] && ret == 0)
	{
		ft_putstr_fd("ft_minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
	}
	if (ret == -1)
	{
		ft_putstr_fd("ft_minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void	print_error_cant_exec(char *cmd)
{
	ft_putstr_fd("ft_minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": can't execute the specified file", 2);
}

void	print_error_lstat(char *cmd, int error)
{
	ft_putstr_fd("ft_minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (error == 1)
		ft_putendl_fd(": No such file or directory", 2);
	else if (error == 2)
		ft_putendl_fd(": is a directory", 2);
	else
		ft_putendl_fd(": Permission denied", 2);
}

void	print_error_signal(const char *str_sig, int nb_sig)
{
	ft_putstr_fd("ft_minishell: ", 2);
	ft_putstr_fd(str_sig, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(nb_sig, 2);
	ft_putchar_fd('\n', 2);
}

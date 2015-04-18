/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:50:52 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/30 10:08:01 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <libft.h>
#include <signal.h>
#include <stdlib.h>

#define SHPROMPT "ft_minishell-1.0$ "

static void		signal_ctrl_c(int signal)
{
	signal = signal;
}

static void		prepare_for_new_cmd(t_sh *sh)
{
	free(sh->cmd);
	sh->cmd = NULL;
	sh->path_cmd = NULL;
	ft_putstr(SHPROMPT);
}

static void		interpret_ret(t_sh *sh, int ret)
{
	if (ret == 1)
		cmd_detected(sh);
	else if (ret == 2)
		bdin_detected(sh);
	else
		print_error_bad_cmd(sh->cmd[0], ret);
}

int				main(void)
{
	t_sh			sh;
	int				ret;
	char			*line;

	signal(SIGINT, &signal_ctrl_c);
	init_struct_sh(&sh);
	ft_putstr(SHPROMPT);
	while (get_next_line(0, &line) > 0)
	{
		init_after_gnl(&sh, line);
		ret = check_the_cmd(&sh);
		interpret_ret(&sh, ret);
		prepare_for_new_cmd(&sh);
	}
	ft_putendl_fd("exit", 2);
	return (0);
}

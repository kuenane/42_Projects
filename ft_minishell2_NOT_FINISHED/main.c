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

/*
**  BONUS :
**	bdin pwd/chdir/echo/exit/crypt/rand/sort + ';' + tilde + rights in path
*/

#include "ft_minishell2.h"
#include <libft.h>
#include <signal.h>

#define SHPROMPT "ft_minishell-2.0$ "

static void		signal_ctrl_c(int signal)
{
	(void)signal;
	ft_putchar('\n');
	ft_putstr(SHPROMPT);
}

static void		prepare_for_new_cmd(t_sh *sh)
{
	v_free(sh->cmd);
	v_free(sh->path_cmd);
	sh->cmd = NULL;
	sh->path_cmd = NULL;
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

static void		launch_the_line(t_sh *sh, char **cmdtab)
{
	int			ret;
	int			nbcmd;
	int			i;

	nbcmd = ft_strlen_tab(cmdtab);
	i = -1;
	while (++i < nbcmd)
	{
		init_after_gnl(sh, cmdtab[i]);
		ret = check_the_cmd(sh);
		interpret_ret(sh, ret);
		prepare_for_new_cmd(sh);
	}
	ft_putstr(SHPROMPT);
}

int				main(void)
{
	t_sh		sh;
	char		*line;

	ft_srand();
	signal(SIGINT, &signal_ctrl_c);
	init_struct_sh(&sh);
	ft_putstr(SHPROMPT);
	while (get_next_line(0, &line) > 0)
	{
		replace_tilde(&sh, &line);
		launch_the_line(&sh, ft_strsplit(line, ';'));
	}
	ft_putendl_fd("exit", 2);
	return (0);
}

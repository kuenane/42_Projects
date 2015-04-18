/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:39:25 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/30 09:00:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <libft.h>
#include <unistd.h>
#include <sys/wait.h>

const char	*g_sign[] = {
	"",
	"Hangup",
	"",
	"Quit",
	"Illegal instruction",
	"Trace/BPT trap",
	"Abort trap",
	"EMT trap",
	"Floating point exception",
	"Killed",
	"Bus error",
	"Segmentation fault",
	"Bad system call",
	"",
	"Alarm clock",
	"Terminated",
	"",
	"Stopped",
	"Stopped",
	"",
	"",
	"Stopped",
	"Stopped",
	"",
	"Cputime limit exceeded",
	"Filesize limit exceeded",
	"Virtual timer expired",
	"Profiling timer expired",
	"",
	"",
	"User defined signal 1",
	"User defined signal 2",
	NULL
};

static void	handle_status(int status)
{
	int		signal;

	if (!WIFSIGNALED(status))
		return ;
	signal = WTERMSIG(status);
	if (signal >= 0 && signal < 32 && g_sign[signal][0] != '\0')
		print_error_signal(g_sign[signal], signal);
}

void		cmd_detected(t_sh *sh)
{
	pid_t	pid;
	int		stat;

	if ((check_file_rights(sh->path_cmd)))
		return ;
	pid = fork();
	if (!pid)
	{
		execve(sh->path_cmd, sh->cmd, sh->env);
		print_error_cant_exec(sh->cmd[0]);
	}
	if (pid > 0)
		waitpid(pid, &stat, 0);
	handle_status(stat);
}

int			bdin_detected(t_sh *sh)
{
	if (ft_strequ("cd", sh->cmd[0]))
		return (bdin_cd(sh));
	if (ft_strequ("setenv", sh->cmd[0]))
		return (bdin_setenv(sh));
	if (ft_strequ("unsetenv", sh->cmd[0]))
		return (bdin_unsetenv(sh));
	if (ft_strequ("env", sh->cmd[0]))
		return (bdin_env(sh));
	if (ft_strequ("exit", sh->cmd[0]))
		return (bdin_exit(sh->cmd[1]));
	if (ft_strequ("pwd", sh->cmd[0]))
		return (bdin_pwd(sh));
	if (ft_strequ("echo", sh->cmd[0]))
		return (bdin_echo(sh));
	if (ft_strequ("chdir", sh->cmd[0]))
		return (bdin_chdir(sh));
	return (0);
}

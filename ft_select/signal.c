/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 14:36:20 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 10:17:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>
#include <sys/ioctl.h>

static t_env	*save_env(t_env *env)
{
	static t_env	*statenv = NULL;

	if (env)
		statenv = env;
	return (statenv);
}

static void		signal_foreground(int signl)
{
	t_env	*env;

	env = save_env(NULL);
	if (signl == SIGTSTP)
	{
		ENABLE_OUTPUT;
		ENABLE_CURSOR;
		if (tcsetattr(0, TCSADRAIN, &env->termios_save))
			ft_exit("error: Cannot restore terminal");
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, "\032");
	}
	else
	{
		manage_signals(env);
		init_term(env);
		print_lst(env);
	}
}

static void		signal_sigwinch(int signl)
{
	t_env	*env;

	env = save_env(NULL);
	if (signl == SIGWINCH)
	{
		refresh_term_size(env);
		print_lst(env);
	}
}

static void		signal_leave_properly(int signl)
{
	(void)signl;
	leave_properly(save_env(NULL), NULL);
}

void			manage_signals(t_env *env)
{
	int		i;

	save_env(env);
	i = 0;
	while (++i < 32)
	{
		if (i == SIGTSTP || i == SIGCONT)
			signal(i, &signal_foreground);
		else if (i == SIGCHLD || i == SIGURG || i == SIGIO || i == SIGWINCH)
			signal(i, &signal_sigwinch);
		else
			signal(i, &signal_leave_properly);
	}
}

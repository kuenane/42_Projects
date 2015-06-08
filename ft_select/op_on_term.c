/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:12:45 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 09:38:33 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>

void			clear_the_screen(t_env *env)
{
	char	*tmp;

	if (!(tmp = tgetstr("cl", NULL)))
	{
		ft_putendl("tgetstr error...");
		leave_properly(env, NULL);
	}
	tputs(tmp, 0, ft_tputs_tty);
}

void			refresh_term_size(t_env *env)
{
	struct winsize	tmp;

	ioctl(0, TIOCGWINSZ, &tmp);
	env->hterm = tmp.ws_row - 1;
	env->wterm = tmp.ws_col;
}

void			leave_properly(t_env *env, char *ret)
{
	ENABLE_OUTPUT;
	ENABLE_CURSOR;
	if (tcsetattr(0, TCSADRAIN, &env->termios_save))
		ft_exit("error: Cannot restore terminal");
	if (ret)
		ft_putendl(ret);
	ft_exit(NULL);
}

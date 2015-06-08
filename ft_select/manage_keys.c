/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 22:23:14 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 14:50:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#define DEC_IT n_dec_lst(env->lst_cur, env->wterm / (env->len_biggest + 4))
#define INC_IT n_inc_lst(env->lst_cur, env->wterm / (env->len_biggest + 4))

static void		other_key(t_env *env, int ikey)
{
	t_lst	*tmp;

	tmp = env->lst_cur->next;
	while (tmp != env->lst_cur)
	{
		if (tmp->name[0] == (char)ikey)
		{
			env->lst_cur = tmp;
			return ;
		}
		tmp = tmp->next;
	}
}

static int		calc_nb_selected(t_env *env)
{
	int		count;
	t_lst	*tmp;

	count = 0;
	tmp = env->lst_first->next;
	while (tmp != env->lst_first)
	{
		if (tmp->selected)
			count++;
		tmp = tmp->next;
	}
	if (tmp->selected)
		count++;
	return (count);
}

static void		return_key_pressed(t_env *env)
{
	int		nb_selected;
	char	*ret;
	t_lst	*tmp;

	nb_selected = calc_nb_selected(env);
	ret = NULL;
	tmp = env->lst_first;
	while (nb_selected)
	{
		if (tmp->selected)
		{
			if (!ret)
				ret = v_strdup(tmp->name);
			else
			{
				ret = v_strjoin_free(ret, " ", 1, 0);
				ret = v_strjoin_free(ret, tmp->name, 1, 1);
			}
			nb_selected--;
		}
		tmp = tmp->next;
	}
	leave_properly(env, ret);
}

void			manage_keys(t_env *env, int ikey)
{
	if (IS_TOP_ARROW)
		env->lst_cur = DEC_IT;
	else if (IS_BOT_ARROW)
		env->lst_cur = INC_IT;
	else if (IS_LEFT_ARROW)
		env->lst_cur = env->lst_cur->prev;
	else if (IS_RIGHT_ARROW)
		env->lst_cur = env->lst_cur->next;
	else if (IS_SP)
	{
		env->lst_cur->selected = (env->lst_cur->selected) ? FALSE : TRUE;
		env->lst_cur = env->lst_cur->next;
	}
	else if (IS_DEL)
		env->lst_cur = lst_del_elem(env, env->lst_cur);
	else if (IS_ENT)
		return_key_pressed(env);
	else if (IS_TAB)
		env->colors_mode = (env->colors_mode) ? FALSE : TRUE;
	else if (IS_ESC)
		leave_properly(env, NULL);
	else
		other_key(env, ikey);
}

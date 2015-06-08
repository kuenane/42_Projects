/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 15:08:08 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/08 14:55:54 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/stat.h>

#define IS_TAR (ft_strequ(&name[ft_strlen(name) - 4], ".tar"))
#define IS_RAR (ft_strequ(&name[ft_strlen(name) - 4], ".rar"))
#define IS_ZIP (ft_strequ(&name[ft_strlen(name) - 4], ".zip"))
#define IS_PDF (ft_strequ(&name[ft_strlen(name) - 4], ".pdf"))
#define IS_AUTH (ft_strequ(name, "auteur"))

static int	cur_link_color(char *name)
{
	struct stat		l_s;

	if (lstat(name, &l_s) < 0)
		return (COL_ERROR);
	if ((S_ISDIR(l_s.st_mode)))
		return (COL_DIR);
	if ((S_ISREG(l_s.st_mode)) && (l_s.st_mode & (S_IXUSR)) == (S_IXUSR))
		return (COL_BIN);
	if ((S_ISREG(l_s.st_mode)) && (IS_TAR || IS_RAR || IS_ZIP))
		return (COL_ARCH);
	if ((S_ISREG(l_s.st_mode)) && (IS_PDF))
		return (COL_PDF);
	if ((S_ISREG(l_s.st_mode)) && (IS_AUTH))
		return (COL_AUTH);
	return (COL_OTHER);
}

t_lst		*lst_new_elem(char *name, t_lst *prev)
{
	t_lst	*new;

	new = (t_lst*)v_malloc(sizeof(t_lst));
	new->name = ft_strdup(name);
	new->selected = FALSE;
	new->prev = prev;
	new->color = cur_link_color(name);
	return (new);
}

t_lst		*lst_del_elem(t_env *env, t_lst *elem)
{
	t_lst	*prev;
	t_lst	*next;

	if (elem == env->lst_first)
		env->lst_first = elem->next;
	prev = elem->prev;
	next = elem->next;
	ft_free(elem->name);
	ft_free(elem);
	prev->next = next;
	next->prev = prev;
	env->nb_link--;
	if (!env->nb_link)
		leave_properly(env, NULL);
	return (next);
}

t_lst		*n_inc_lst(t_lst *tmp, int n)
{
	while (n > 0)
	{
		tmp = tmp->next;
		n--;
	}
	return (tmp);
}

t_lst		*n_dec_lst(t_lst *tmp, int n)
{
	while (n > 0)
	{
		tmp = tmp->prev;
		n--;
	}
	return (tmp);
}

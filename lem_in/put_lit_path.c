/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lit_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 16:35:44 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/16 09:39:16 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define RESET_CELL(x) tsearch_assign_cell(x, -1, -1)
#define CUR_CELL &curpath[cursize - 1]
#define CUR_ID curpath[cursize - 1].id
#define CUR_INDEX curpath[cursize - 1].index
#define NXT_CELL &curpath[cursize]
#define PREV_ID curpath[cursize - 2].id

static t_bool		is_in_prev_tubes(t_env *env, int prev_id, int next_id)
{
	int		i;

	i = -1;
	while (++i < NB_TUBES(prev_id))
		if (TUBE(prev_id, i) == next_id)
			return (TRUE);
	return (FALSE);
}

static void			tsearch_assign_cell(t_search *cell, int newid, int newindex)
{
	cell->id = newid;
	cell->index = newindex;
}

static void			replace_lit_path(t_env *env, t_search *newpath, int newsize)
{
	if (LIT_PATHTAB)
		ft_free(LIT_PATHTAB);
	SIZE_LIT_PATH = newsize + 1;
	LIT_PATHTAB = (int*)v_malloc(sizeof(int) * (newsize + 1));
	LIT_PATH(newsize) = END_ROOM;
	while (--newsize >= 0)
		LIT_PATH(newsize) = newpath[newsize].id;
}

static int			rec_search(t_env *env, t_search *curpath, int cursize)
{
	if (!NB_TUBES(CUR_ID) || cursize + 1 >= SIZE_LIT_PATH)
		return (RESET_CELL(CUR_CELL), 1);
	if (is_linked_with_endroom(env, CUR_ID))
	{
		replace_lit_path(env, curpath, cursize);
		return (RESET_CELL(CUR_CELL), 1);
	}
	while (++CUR_INDEX < NB_TUBES(CUR_ID))
	{
		if ((cursize > 1 && (PREV_ID == TUBE(CUR_ID, CUR_INDEX)
			|| TUBE(CUR_ID, CUR_INDEX) == START_ROOM)) || (cursize > 2
			&& is_in_prev_tubes(env, PREV_ID, TUBE(CUR_ID, CUR_INDEX))))
			continue;
		tsearch_assign_cell(NXT_CELL, TUBE(CUR_ID, CUR_INDEX), -1);
		rec_search(env, curpath, cursize + 1);
		RESET_CELL(NXT_CELL);
	}
	return (1);
}

void				put_lit_path(t_env *env)
{
	t_search	curpath[NB_ROOMS];
	int			cursize;

	tsearch_assign_cell(&curpath[0], START_ROOM, -1);
	cursize = 0;
	while (++cursize < NB_ROOMS)
		RESET_CELL(&curpath[cursize]);
	cursize = 1;
	rec_search(env, &curpath[0], cursize);
}

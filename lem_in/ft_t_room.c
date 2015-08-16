/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 11:13:12 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/16 09:39:13 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	is_linked_with_endroom(t_env *env, int my_id)
{
	int		i;

	i = -1;
	while (++i < NB_TUBES(my_id))
		if (TUBE(my_id, i) == END_ROOM)
			return (TRUE);
	return (FALSE);
}

t_room	**new_troomtab(t_room *toadd)
{
	t_room	**tab;

	tab = (t_room**)v_malloc(sizeof(t_room*));
	tab[0] = toadd;
	return (tab);
}

t_room	**add_troom_totab(t_room **tab, t_room *toadd, int tabsize)
{
	t_room	**new;
	int		i;

	new = (t_room**)v_malloc(sizeof(t_room*) * (tabsize + 2));
	i = -1;
	while (++i < tabsize)
		new[i] = tab[i];
	new[i] = toadd;
	ft_free(tab);
	return (new);
}

t_room	*ft_newtroom(int id, char *name, int posx, int posy)
{
	t_room	*new;

	new = (t_room*)v_malloc(sizeof(t_room));
	new->id = id;
	new->name = name;
	new->tubes_id = (int*)v_malloc(sizeof(int));
	new->nb_tubes = 0;
	new->posx = posx;
	new->posy = posy;
	return (new);
}

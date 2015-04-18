/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 09:23:23 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/27 15:44:05 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phi.h>

/*
** les fonctions start doivent etre betes,
** les fonctions end prennent les decisions,
*/

void			phi_eat_start_event(t_env *e, int id)
{
	e->official_s[id] = eat;
	e->act_end_time[id] = e->last_time + EAT_T;
	e->eating_delta[id] = (MAX_LIFE - e->phi_hp[id]) / EAT_T;
	e->stick_state_change = 1;
	return ;
}

void			phi_eat_end_event(t_env *e, int id)
{
	e->phi_hp[id] = MAX_LIFE;
	pthread_mutex_unlock(&e->mutex[P_LSID(id)]);
	pthread_mutex_unlock(&e->mutex[P_RSID(id)]);
	e->llock[id] = ignored;
	e->rlock[id] = ignored;
	e->stick_state_change = 1;
	phi_rest_start_event(e, id);
	return ;
}

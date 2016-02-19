/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_inttabnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:50:33 by wide-aze          #+#    #+#             */
/*   Updated: 2015/07/14 11:09:59 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		*v_inttabnew(int nb)
{
	int		*new;

	new = (int*)v_malloc(sizeof(int));
	new[0] = nb;
	return (new);
}

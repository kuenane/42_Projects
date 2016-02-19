/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_replace_free2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:03:18 by wide-aze          #+#    #+#             */
/*   Updated: 2016/02/14 09:42:31 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*v_replace_free2(char *old, char *new, t_bool fnew)
{
	char	*tmp;

	tmp = v_strdup(new);
	ft_free(old);
	if (fnew)
		ft_free(new);
	return (tmp);
}

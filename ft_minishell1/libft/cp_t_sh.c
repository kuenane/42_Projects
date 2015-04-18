/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_t_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 09:09:55 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/28 10:18:33 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell1.h"
#include <libft.h>

t_sh	*cp_t_sh(t_sh *src)
{
	t_sh	*new;

	new = (t_sh*)verified_malloc(sizeof(t_sh) * 1);
	new->cmd = cp_env_tab(src->cmd);
	new->env = NULL;
	new->path_cmd = NULL;
	return (new);
}

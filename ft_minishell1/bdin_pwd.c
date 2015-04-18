/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:44:37 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/26 15:47:39 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>

int		bdin_pwd(t_sh *sh)
{
	char	*tmp;

	if (sh->cmd[1])
		return (ft_putendl_fd("pwd: too many arguments", 2), 1);
	if ((tmp = getcwd(NULL, PATH_MAX + 1)))
	{
		ft_putendl(tmp);
		free(tmp);
		return (0);
	}
	return (1);
}

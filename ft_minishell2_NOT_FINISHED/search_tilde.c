/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 17:27:20 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/01 17:50:41 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>

static void		ft_insert_it(char **line, int i, char *home)
{
	char	*new;

	if (home[ft_strlen(home) - 1] != '/' && line[0][i + 1] != '/')
		home = v_strjoin(home, "/");
	else
		home = v_strdup(home);
	new = v_strnew(ft_strlen(*line) + ft_strlen(home));
	ft_strncpy(new, *line, i);
	ft_strcat(new, home);
	ft_strcat(new, &line[0][i + 1]);
	v_free(*line);
	*line = new;
	v_free(home);
}

void			replace_tilde(t_sh *sh, char **line)
{
	char	*home;
	int		i;

	if (!(home = search_in_envp(sh, "HOME")) || !line || !*line)
		return ;
	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '~')
			ft_insert_it(line, i, home);
		i++;
	}
}

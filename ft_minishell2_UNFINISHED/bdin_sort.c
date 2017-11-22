/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bdin_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 10:31:56 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/03 13:35:27 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>

static void		sort_rand(char **tab)
{
	(void)tab;
}

static int		sort_it(char **args, char type)
{
	int		i;

	if (type == 'a')
		ft_quicksort_str(args, 0, ft_strlen_tab(args) - 1);
	else if (type == 'd')
		ft_quicksort_str_dsc(args, 0, ft_strlen_tab(args) - 1);
	else
		sort_rand(args);
	i = 0;
	while (args[i])
	{
		ft_putendl(args[i]);
		i++;
	}
	return (0);
}

int				bdin_sort(t_sh *sh)
{
	if (!sh->cmd[1] || !sh->cmd[2])
		return (ft_putendl_fd("usage: sort [-asc/dsc/rand] [args...]", 2), 1);
	if (ft_strequ(sh->cmd[1], "-asc"))
		return (sort_it(&sh->cmd[2], 'a'));
	if (ft_strequ(sh->cmd[1], "-dsc"))
		return (sort_it(&sh->cmd[2], 'd'));
	if (ft_strequ(sh->cmd[1], "-rand"))
		return (sort_it(&sh->cmd[2], 'r'));
	return (ft_putendl_fd("usage: sort [-asc/dsc/rand] [args...]", 2), 0);
}

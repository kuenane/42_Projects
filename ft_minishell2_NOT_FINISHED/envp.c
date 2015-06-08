/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:42:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/30 10:05:52 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>

char	*pwd_without_end(t_sh *sh)
{
	char	*pwd;
	int		i;

	pwd = search_in_envp(sh, "PWD");
	i = ft_strlen(pwd);
	if (pwd[i] == '/')
		i--;
	while (pwd[i] != '/')
		i--;
	return (ft_strsub(pwd, 0, i + 1));
}

char	*pwd_with_end(t_sh *sh)
{
	char	*pwd;

	pwd = search_in_envp(sh, "PWD");
	if (pwd[ft_strlen(pwd) - 1] != '/')
		return (ft_strjoin(pwd, "/"));
	return (ft_strdup(pwd));
}

char	*search_in_envp(t_sh *sh, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (sh == NULL || sh->env == NULL || sh->env[0] == NULL)
		return (NULL);
	while (sh->env[i] != NULL)
	{
		if (ft_strnequ(sh->env[i], str, len))
			return (&sh->env[i][len + 1]);
		i++;
	}
	return (NULL);
}

char	*search_in_chartab(char **tab, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (tab[i])
	{
		if (ft_strnequ(tab[i], str, len))
			return (&tab[i][len + 1]);
		i++;
	}
	return (NULL);
}

t_sh	*manage_shlvl(t_sh *sh)
{
	int		i;
	char	*tmp;

	if (!(search_in_envp(sh, "SHLVL=")))
		sh->env = add_str_to_tab(sh->env, "SHLVL=0");
	i = 0;
	while (sh->env[i] && ft_strncmp(sh->env[i], "SHLVL=", 6))
		i++;
	tmp = v_strjoin("SHLVL=", ft_itoa((ft_atoi(&sh->env[i][6]) + 1)));
	v_free(sh->env[i]);
	sh->env[i] = tmp;
	return (sh);
}

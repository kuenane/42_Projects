/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CRYPT.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 10:31:56 by wide-aze          #+#    #+#             */
/*   Updated: 2015/05/03 18:13:50 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include <libft.h>

static char		encrypt_char(int c, int kmod)
{
	if (ft_isalpha(c))
	{
		if (c <= 'Z' && (c + kmod % 26) > 'Z')
			return (c + kmod % 26 - 26);
		if ((c += kmod % 26) > 122)
			c -= 26;
	}
	else if (ft_isdigit(c))
	{
		if ((c += kmod % 10) > '9')
			c -= 10;
	}
	else if (c >= 58 && c <= 64)
	{
		if ((c += kmod % 7) > 64)
			c -= 7;
	}
	else if (c >= 35 && c <= 47)
	{
		if ((c += kmod % 13) > 47)
			c -= 13;
	}
	return (c);
}

static char		decrypt_char(int c, int kmod)
{
	if (ft_isalpha(c))
	{
		if (c >= 'a' && (c - kmod % 26) < 'a')
			return (c - kmod % 26 + 26);
		if ((c -= kmod % 26) < 65)
			c += 26;
	}
	else if (ft_isdigit(c))
	{
		if ((c -= kmod % 10) < 48)
			c += 10;
	}
	else if (c >= 58 && c <= 64)
	{
		if ((c -= kmod % 7) < 58)
			c += 7;
	}
	else if (c >= 35 && c <= 47)
	{
		if ((c -= kmod % 13) < 35)
			c += 13;
	}
	return (c);
}

void			encrypt(char *msg, char *key)
{
	char	*keysave;

	keysave = key;
	while (*msg != '\0')
	{
		ft_putchar(encrypt_char(*(msg++), *(key++)));
		if (key == '\0')
			key = keysave;
	}
	ft_putchar('\n');
}

void			decrypt(char *msg, char *key)
{
	char	*keysave;

	keysave = key;
	while (*msg != '\0')
	{
		ft_putchar(decrypt_char(*(msg++), *(key++)));
		if (key == '\0')
			key = keysave;
	}
	ft_putchar('\n');
}

int				bdin_crypt(t_sh *sh, char c)
{
	char	*tmp;

	if (!sh->cmd[1] || !sh->cmd[2] || !sh->cmd[1][0] || !sh->cmd[2][0])
		return (ft_putendl_fd("usage: [encrypt/decrypt] [msg] [key]", 2), 0);
	while (ft_strlen(sh->cmd[1]) > ft_strlen(sh->cmd[2]))
	{
		tmp = sh->cmd[2];
		sh->cmd[2] = ft_strjoin(sh->cmd[2], sh->cmd[2]);
		v_free(tmp);
	}
	if (c == 'e')
		return (encrypt(sh->cmd[1], sh->cmd[2]), 1);
	return (decrypt(sh->cmd[1], sh->cmd[2]), 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 15:42:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/19 17:07:27 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <libft.h>
#include <stdlib.h>
#include <wchar.h>

static int	ft_putstr_int(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &(str[i++]), 1);
	return (i);
}

static char	*contain_tab7(char *str, int *tab)
{
	char	*new;

	new = ft_strnew(tab[7]);
	return (ft_strncpy(new, str, tab[7]));
}

static char	*s_upcase(wchar_t *wstr)
{
	char		*str;
	int			len;

	if (!wstr)
		return (ft_strdup("(null)"));
	len = (ft_wstrlen(wstr) * 4);
	str = (char*)verified_malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (len)
		ft_wstr_to_str(str, wstr);
	return (str);
}

int			option_s(int *tab, va_list ap)
{
	char	*str;
	int		len;

	if (!tab[10])
		str = va_arg(ap, char*);
	else
		str = s_upcase(va_arg(ap, wchar_t*));
	if (!str)
		return (write(1, "(null)", 6), 6);
	if (tab[7] != -424242)
		str = contain_tab7(str, tab);
	str = apply_width_min(str, tab);
	len = ft_putstr_int(str);
	free(str);
	return (len);
}

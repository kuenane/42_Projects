/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_option_parse_len.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:26:13 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/08 10:35:37 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		current_option_parse_len(char *s, int i)
{
	while (s[i] == '%' || s[i] == '-' || s[i] == '+' || s[i] == '#'
	|| s[i] == '0' || s[i] == ' ')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
	{
		i++;
		while (ft_isdigit(s[i]))
			i++;
	}
	while (s[i] == 'h' || s[i] == 'j' || s[i] == 'l' || s[i] == 'z')
		i++;
	return (i);
}

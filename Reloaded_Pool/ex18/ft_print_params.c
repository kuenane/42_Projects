/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:22:06 by wide-aze          #+#    #+#             */
/*   Updated: 2016/11/01 00:07:33 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i != ac)
	{
		ft_putstr(av[i]);
		ft_putstr("\n");
	}
	return (0);
}

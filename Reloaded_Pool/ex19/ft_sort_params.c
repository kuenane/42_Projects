/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:22:06 by wide-aze          #+#    #+#             */
/*   Updated: 2016/11/05 15:39:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (4242);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while ((*str1 == *str2) && (*str1) && (*str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int		main(int ac, char **av)
{
	char	*swap;
	int		i;
	int		j;

	i = 0;
	while (++i != ac)
	{
		j = 0;
		while (++j != ac)
		{
			if (i != j && ft_strcmp(av[i], av[j]) < 0)
			{
				swap = av[i];
				av[i] = av[j];
				av[j] = swap;
				j = 0;
			}
		}
	}
	i = 0;
	while (++i != ac)
		ft_putendl(av[i]);
	return (0);
}

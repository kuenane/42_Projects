/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_struct_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 11:19:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 08:31:58 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_the_nb(char *str)
{
	int		len;
	int		is_neg;

	if (*str == '-' && str[1] == '\0')
		ft_exit("Error");
	len = 0;
	is_neg = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg++;
		str++;
	}
	while (*str == '0')
		str++;
	while (str[len])
	{
		if (!ft_isdigit(str[len]) || len > 10)
			ft_exit("Error");
		len++;
	}
	if (len > 10 || (is_neg == 0 && len == 10 &&
	ft_strcmp(str, "2147483647") > 0) || (is_neg == 1 && len == 10 &&
	ft_strcmp(str, "2147483648") > 0))
		ft_exit("Error");
}

static void		vi_found(int *ac, char **av)
{
	int		i;

	i = 1;
	while (i < *ac)
	{
		swap_two_str(&av[i], &av[i + 1]);
		i++;
	}
	av[*ac] = NULL;
	*ac = *ac - 1;
}

static void		check_option_vi(int *ac, char **av, t_ps *ps)
{
	if (ft_strequ(av[1], "-v"))
		return (ps->v++, vi_found(ac, av));
	if (ft_strequ(av[1], "-i"))
		return (ps->i++, vi_found(ac, av));
	if (ft_strequ(av[1], "-vi") || ft_strequ(av[1], "-iv"))
		return (ps->v++, ps->i++, vi_found(ac, av));
}

static void		check_and_put_savereal(int *ac, char **av, t_ps *ps)
{
	int		i;

	if (*ac == 0)
		ft_exit("Error");
	ps->save_real = (int*)v_malloc(sizeof(int) * (*ac));
	check_option_vi(ac, av, ps);
	i = 1;
	while (i <= *ac)
	{
		check_the_nb(av[i]);
		ps->save_real[i - 1] = ft_atoi(av[i]);
		i++;
	}
}

void			put_struct_ps(int *ac, char **av, t_ps *ps)
{
	*ac = *ac - 1;
	ps->v = 0;
	ps->i = 0;
	check_and_put_savereal(ac, av, ps);
	put_a_b_solved(ps, *ac);
}

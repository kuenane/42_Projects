/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 20:45:27 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 20:09:39 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	char	**add_str_strtab(char **tab, char *str)
**  int		ft_strlen_strtab(char **tab)
**  void	restore_a_b_stack(t_ps *ps, int ac)
**  void	ft_putstrtab(char **tab, char *delimiter, char *ender)
*/

#include "push_swap.h"

static void		print_best_sorted(t_alg *bf, t_alg *smt, t_alg *v1, t_alg *v2)
{
	if (bf->nb <= smt->nb && bf->nb <= v1->nb && bf->nb <= v2->nb)
		ft_putstrtab(bf->act, " ", "\n");
	else if (smt->nb <= bf->nb && smt->nb <= v1->nb && smt->nb <= v2->nb)
		ft_putstrtab(smt->act, " ", "\n");
	else if (v1->nb <= smt->nb && v1->nb <= bf->nb && v1->nb <= v2->nb)
		ft_putstrtab(v1->act, " ", "\n");
	else
		ft_putstrtab(v2->act, " ", "\n");
}

static void		init_t_alg(t_alg *bf, t_alg *smsort, t_alg *var1, t_alg *var2)
{
	bf->act = ft_strtabnew(0);
	bf->nb = 0;
	smsort->act = ft_strtabnew(0);
	smsort->nb = 0;
	var1->act = ft_strtabnew(0);
	var1->nb = 0;
	var2->act = ft_strtabnew(0);
	var2->nb = 0;
}

static void		init_and_put_v2v3(t_ps *ps, t_alg *var2, t_alg *var3, int ac)
{
	var3->act = ft_strtabnew(0);
	var3->nb = 0;
	restore_a_b_stack(ps, ac);
	put_algo_various2(var2, ps, ac, 0);
	restore_a_b_stack(ps, ac);
	put_algo_various3(var3, ps, ac, 0);
}

void			normal_mode(t_ps *ps, int ac)
{
	t_alg	bf;
	t_alg	smsort;
	t_alg	var1;
	t_alg	var2;
	t_alg	var3;

	if (!check_if_solved(ps->a, ps->solved, ac))
		return ;
	if (ac < 20 && ps->v == 0)
	{
		init_t_alg(&bf, &smsort, &var1, &var2);
		put_algo_bruteforce(&bf, ps, ac);
		restore_a_b_stack(ps, ac);
		put_algo_smartsort(&smsort, ps, ac, ac);
		restore_a_b_stack(ps, ac);
		put_algo_various1(&var1, ps, ac, 0);
		init_and_put_v2v3(ps, &var2, &var3, ac);
		if (var2.nb < var3.nb)
			print_best_sorted(&bf, &smsort, &var1, &var2);
		else
			print_best_sorted(&bf, &smsort, &var1, &var3);
	}
	else
		print_smartsort(ps, ac, ac, 0);
}

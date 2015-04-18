/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:54:23 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 19:45:11 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		vbose_enabled(t_ps *ps, int ac)
{
	ft_putstr("a: ");
	print_converted_stack(ps, ps->a, ac);
	ft_putstr("b: ");
	print_converted_stack(ps, ps->b, ac);
	ft_putchar('\n');
}

static void		apply_action(t_ps *ps, char *line, int ac)
{
	if (ft_strequ("sa", line))
		action_sa(ps->a);
	else if (ft_strequ("sb", line))
		action_sb(ps->b);
	else if (ft_strequ("ss", line))
		action_ss(ps->a, ps->b);
	else if (ft_strequ("pa", line))
		action_pa(ps->a, ps->b, ac);
	else if (ft_strequ("pb", line))
		action_pb(ps->a, ps->b, ac);
	else if (ft_strequ("ra", line))
		action_ra(ps->a, ac);
	else if (ft_strequ("rb", line))
		action_rb(ps->b, ac);
	else if (ft_strequ("rr", line))
		action_rr(ps->a, ps->b, ac);
	else if (ft_strequ("rra", line))
		action_rra(ps->a, ac);
	else if (ft_strequ("rrb", line))
		action_rrb(ps->b, ac);
	else
		action_rrr(ps->a, ps->b, ac);
	if (ps->v)
		vbose_enabled(ps, ac);
}

static int		check_input(char *line)
{
	if (ft_strequ("exit", line))
		ft_exit("will exit now...");
	if (ft_strequ("sa", line) || ft_strequ("sb", line)
	|| ft_strequ("ss", line) || ft_strequ("pa", line) || ft_strequ("pb", line)
	|| ft_strequ("ra", line) || ft_strequ("rb", line) || ft_strequ("rr", line)
	|| ft_strequ("rra", line) || ft_strequ("rrb", line)
	|| ft_strequ("rrr", line))
		return (1);
	return (ft_putendl("input error"), 0);
}

static void		print_begin(void)
{
	ft_putendl(" ------------------\n| INTERACTIVE MODE |");
	ft_putendl(" ------------------");
	ft_putstr("usage: [sa sb ss pa pb ra rb rr rra rrb rrr]");
	ft_putendl(" ('exit' for exit...)\n");
}

void			interactive_mode(t_ps *ps, int ac)
{
	char	*line;

	print_begin();
	vbose_enabled(ps, ac);
	while (check_if_solved(ps->a, ps->solved, ac))
	{
		get_next_line(0, &line);
		if (check_input(line))
			apply_action(ps, line, ac);
	}
	ft_putendl("a stack is sorted :)");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:41:04 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/03 19:42:48 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct	s_ps
{
	int			*save_real;
	int			*save_new;
	int			*a;
	int			*b;
	int			*solved;
	int			v;
	int			i;
}				t_ps;

typedef struct	s_alg
{
	char		**act;
	int			nb;
}				t_alg;

void			put_struct_ps(int *ac, char **av, t_ps *ps);
void			put_a_b_solved(t_ps *ps, int ac);
void			print_stack(int *stack, int ac);
void			verbose_enabled(t_ps *ps, int *a, int *b, int ac);
int				*convert_stack(t_ps *ps, int *a, int ac);
void			print_converted_stack(t_ps *ps, int *stack, int ac);
int				check_if_solved(int *a, int *solved, int ac);
void			put_algo_bruteforce(t_alg *alg, t_ps *ps, int ac);
void			put_algo_smartsort(t_alg *alg, t_ps *ps, int ac, int len);
void			put_algo_various1(t_alg *alg, t_ps *ps, int ac, int i);
void			put_algo_various2(t_alg *alg, t_ps *ps, int ac, int i);
void			put_algo_various3(t_alg *alg, t_ps *ps, int ac, int i);
void			print_smartsort(t_ps *ps, int ac, int len, int smpos);
void			interactive_mode(t_ps *ps, int ac);
void			normal_mode(t_ps *ps, int ac);
void			cpy_stack(int *src, int *dst, int ac);
void			restore_a_b_stack(t_ps *ps, int ac);
void			put_it_on_top(int *stack, int nb, int ac);
void			put_it_on_bot(int *stack, int nb);
void			del_the_top(int *stack, int ac);
void			desc_the_stack(int *stack, int ac);
int				len_stack(int *stack, int ac);
int				smaller_pos(int *stack, int len);
void			push_b_to_a(t_ps *ps, t_alg *alg, int ac);
void			action_sa(int *a);
void			action_sb(int *b);
void			action_ss(int *a, int *b);
void			action_pa(int *a, int *b, int ac);
void			action_pb(int *a, int *b, int ac);
void			action_ra(int *a, int ac);
void			action_rb(int *b, int ac);
void			action_rr(int *a, int *b, int ac);
void			action_rra(int *a, int ac);
void			action_rrb(int *b, int ac);
void			action_rrr(int *a, int *b, int ac);

#endif

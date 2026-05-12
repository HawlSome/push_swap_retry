/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:48:17 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 02:59:50 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_there_executable_flag(t_flags *flag)
{
	size_t	count;

	count = 0;
	while (flag)
	{
		if (is_executable_flag(flag))
			count++;
		flag = flag->next;
	}
	if (!count)
		return (0);
	return (1);
}

static void	execute_flag(t_stack **stack_a, t_stack **stack_b, t_moves **moves,
				t_flags **flag)
{
	float	disorder;
	t_flags	*executable_flag;

	disorder = compute_disorder(*stack_a);
	if (disorder > -1e-6f && disorder < 1e-6f)
		return ;
	executable_flag = get_executable_flag(*flag);
	if (!ft_strcmp(executable_flag->algo, "adaptive"))
		algo_adaptive(stack_a, stack_b, moves, flag);
	else if (!ft_strcmp(executable_flag->algo, "simple"))
		algo_simple(stack_a, stack_b, moves);
	else if (!ft_strcmp(executable_flag->algo, "medium"))
		algo_medium(stack_a, stack_b, moves);
	else if (!ft_strcmp(executable_flag->algo, "complex"))
		algo_complex(stack_a, stack_b, moves);
}

static void	output_moves(t_moves *moves)
{
	while (moves)
	{
		ft_printf(1, "%s\n", moves->name);
		moves = moves->next;
	}
}

static void	execute_bench(t_flags **flags, t_moves **moves, float disorder)
{
	if (is_elem_in_flags(*flags, "bench"))
		bench_mark(disorder, flags, moves);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, t_moves **moves,
			t_flags **flags)
{
	float	disorder;

	if (!stack_a || !*stack_a)
		return ;
	disorder = compute_disorder(*stack_a);
	if (!is_there_executable_flag(*flags))
		new_flag(flags, "adaptive", 1);
	execute_flag(stack_a, stack_b, moves, flags);
	output_moves(*moves);
	execute_bench(flags, moves, disorder);
}

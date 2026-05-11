/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 00:21:49 by varandri          #+#    #+#             */
/*   Updated: 2026/05/11 19:24:39 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_index_min(t_stack *stack_a)
{
	t_stack	*min_node;

	min_node = stack_a;
	while (stack_a)
	{
		if (stack_a->index < min_node->index)
			min_node = stack_a;
		stack_a = stack_a->next;
	}
	return (min_node->index);
}

static int	member_in_range(t_stack *stack_a, long min, long max)
{
	int	count;

	count = 0;
	while (stack_a)
	{
		if (stack_a->index >= min && stack_a->index <= max)
			count ++;
		stack_a = stack_a->next;
	}
	return (count);
}

static int	is_in_range(t_stack *stack_a, long min, long max)
{
	return (
		stack_a->index >= min && stack_a->index <= max
	);
}

static void	sort_new_elem_b(t_stack **stack_b, t_moves **moves)
{
	if (
		*stack_b && (*stack_b)->next
		&& ((*stack_b)->index < ((*stack_b)->next)->index)
	)
		sb(stack_b, moves, 1);
}

void	algo_medium(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	long	range_min;
	long	range_max;
	size_t	range_step;

	if (size_stack(*stack_a) <= 5)
		return (algo_least_five(stack_a, stack_b, moves));
	attribute_index(*stack_a);
	range_step = (size_stack(*stack_a)) / ft_sqrt(size_stack(*stack_a));
	range_min = find_index_min(*stack_a);
	range_max = range_min + (long)range_step;
	while (*stack_a)
	{
		while (*stack_a && !member_in_range(*stack_a, range_min, range_max))
		{
			range_min = range_max + 1;
			range_max = range_min + range_step;
		}
		while (*stack_a && !is_in_range(*stack_a, range_min, range_max))
			ra(stack_a, moves, 1);
		pb(stack_a, stack_b, moves, 1);
		sort_new_elem_b(stack_b, moves);
	}
	push_back_medium(stack_a, stack_b, moves);
}

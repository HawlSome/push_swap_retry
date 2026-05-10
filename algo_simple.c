/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 07:00:24 by varandri          #+#    #+#             */
/*   Updated: 2026/05/10 10:18:06 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_min(t_stack *stack_node)
{
	t_stack	*min;
	size_t	index;
	size_t	min_index;

	min = stack_node;
	min_index = 0;
	index = 0;
	while (stack_node)
	{
		if (stack_node->value < min->value)
		{
			min = stack_node;
			min_index = index;
		}
		index ++;
		stack_node = stack_node->next;
	}
	return (min_index);
}

// static void	placing_min(t_stack **stack_a, t_moves **moves,
// 	size_t min_index, char *direction)
// {
// 	while (min_index)
// 	{
// 		if (!ft_strcmp(direction, "up"))
// 			ra(stack_a, moves, 1);
// 		if (!ft_strcmp(direction, "down"))
// 			rra(stack_a, moves, 1);
// 		min_index --;
// 	}
// }

void	algo_simple(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	size_t	stack_min_index;
	size_t	size_stack_a;

	size_stack_a = size_stack(*stack_a);
	stack_min_index = 0;
	while (size_stack_a > 5)
	{
		stack_min_index = find_min(*stack_a);
		// if (stack_min_index && stack_min_index < size_stack_a / 2)
		// 	placing_min(stack_a, moves, stack_min_index, "up");
		// if (stack_min_index && stack_min_index > size_stack_a / 2)
		// 	placing_min(stack_a, moves,
		// 		(size_stack_a - stack_min_index), "down");
		if (stack_min_index)
		{
			while (stack_min_index)
			{
				ra(stack_a, moves, 1);
				stack_min_index --;
			}
		}
		pb(stack_a, stack_b, moves, 1);
		size_stack_a --;
	}
	algo_least_five(stack_a, stack_b, moves);
}

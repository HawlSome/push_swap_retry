/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_least_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:12:37 by varandri          #+#    #+#             */
/*   Updated: 2026/05/11 02:45:15 by varandri         ###   ########.fr       */
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

static size_t	find_max(t_stack *stack_node)
{
	t_stack	*max;
	size_t	index;
	size_t	max_index;

	max = stack_node;
	max_index = 0;
	index = 0;
	while (stack_node)
	{
		if (stack_node->value > max->value)
		{
			max = stack_node;
			max_index = index;
		}
		index ++;
		stack_node = stack_node->next;
	}
	return (max_index);
}

static void	sort_three_max(t_stack **stack_a, t_moves **moves)
{
	size_t	max_index;

	max_index = find_max(*stack_a);
	if (!max_index)
		ra(stack_a, moves, 1);
	if (max_index == 1)
		rra(stack_a, moves, 1);
}

void	algo_least_five(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	size_t	min_index;
	size_t	size_stack_a;

	if (!stack_a || !*stack_a)
		return ;
	size_stack_a = size_stack(*stack_a);
	while (size_stack_a > 3)
	{
		min_index = find_min(*stack_a);
		while (min_index)
		{
			ra(stack_a, moves, 1);
			min_index --;
		}
		pb(stack_a, stack_b, moves, 1);
		size_stack_a --;
	}
	if (size_stack_a == 3)
	{
		sort_three_max(stack_a, moves);
		if ((*stack_a)->value > ((*stack_a)->next->value))
			sa(stack_a, moves, 1);
	}
	push_back(stack_a, stack_b, moves);
}

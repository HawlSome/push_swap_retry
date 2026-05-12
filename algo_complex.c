/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramandri <ramandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:14:03 by ramandri          #+#    #+#             */
/*   Updated: 2026/05/12 09:46:07 by ramandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_max_index(t_stack *stack_a)
{
	t_stack	*max;

	max = stack_a;
	while (stack_a)
	{
		if (stack_a->index > max->index)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max->index);
}

static size_t	count_max_bit(t_stack *stack_a)
{
	long	max_index;
	size_t	bit_size;

	max_index = find_max_index(stack_a);
	bit_size = 0;
	while (max_index)
	{
		max_index = max_index >> 1;
		bit_size++;
	}
	return (bit_size);
}

static void	push_bit_rank_0(t_stack **stack_a,
		t_stack **stack_b, t_moves **moves, size_t bit_rank)
{
	size_t	stack_size;
	size_t	current_bit;

	stack_size = size_stack(*stack_a);
	while (stack_size)
	{
		current_bit = ((*stack_a)->index) >> bit_rank & 1;
		if (!current_bit)
			pb(stack_a, stack_b, moves, 1);
		else
			ra(stack_a, moves, 1);
		stack_size --;
	}
}

void	algo_complex(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	size_t	bit_max;
	size_t	bit_rank;

	if (size_stack(*stack_a) <= 5)
		return (algo_least_five(stack_a, stack_b, moves));
	attribute_index(*stack_a);
	bit_max = count_max_bit(*stack_a);
	bit_rank = 0;
	while (bit_rank < bit_max)
	{
		push_bit_rank_0(stack_a, stack_b, moves, bit_rank);
		push_back(stack_a, stack_b, moves);
		bit_rank++;
	}
}

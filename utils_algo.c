/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 01:17:13 by varandri          #+#    #+#             */
/*   Updated: 2026/05/11 19:19:50 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	find_max_index(t_stack *stack)
{
	t_stack	*max;
	size_t	max_index;
	size_t	i;

	max = stack;
	max_index = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max->index)
		{
			max = stack;
			max_index = i;
		}
		stack = stack->next;
		i ++;
	}
	return (max_index);
}

void	attribute_index(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min_node;
	size_t	stack_size;
	long	index;

	if (!stack)
		return ;
	stack_size = size_stack(stack);
	index = 0;
	while (index < (long)stack_size)
	{
		tmp = stack;
		min_node = NULL;
		while (tmp)
		{
			if ((tmp->index == -1)
				&& (!min_node || tmp->value <= min_node->value))
				min_node = tmp;
			tmp = tmp->next;
		}
		if (min_node)
			min_node->index = index;
		index ++;
	}
}

size_t	ft_sqrt(size_t nbr)
{
	size_t	i;

	i = 0;
	while (i * i < nbr)
		i ++;
	if (i * i > nbr)
		i --;
	if (i * i <= nbr)
		return (i);
	return (0);
}

void	push_back(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	while (*stack_b)
		pa(stack_a, stack_b, moves, 1);
}

void	push_back_medium(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	size_t	max_index;
	size_t	stack_size;
	size_t	back_step;

	if (!stack_b || !*stack_b)
		return ;
	while (*stack_b)
	{
		stack_size = size_stack(*stack_b);
		max_index = find_max_index(*stack_b);
		back_step = stack_size - max_index;
		while (max_index && max_index <= stack_size / 2)
		{
			rb(stack_b, moves, 1);
			max_index --;
		}
		while (max_index && max_index > stack_size / 2 && back_step--)
			rrb(stack_b, moves, 1);
		pa(stack_a, stack_b, moves, 1);
	}
}

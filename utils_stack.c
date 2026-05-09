/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:26:45 by varandri          #+#    #+#             */
/*   Updated: 2026/05/09 04:27:43 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*new_stack_node(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = -1;
	stack->next = NULL;
	return (stack);
}

size_t	size_stack(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size ++;
		stack = stack->next;
	}
	return (size);
}

void	stack_add_front(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->next = *stack;
	*stack = node;
}

void	stack_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last_elem;

	if (!node || !stack)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last_elem = stack_last(*stack);
	last_elem->next = node;
}

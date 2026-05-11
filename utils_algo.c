/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:17:13 by varandri          #+#    #+#             */
/*   Updated: 2026/05/11 03:22:45 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

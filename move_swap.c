/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 03:16:09 by varandri          #+#    #+#             */
/*   Updated: 2026/05/10 03:40:30 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	sa(t_stack **stack, t_moves **moves, int save)
{
	swap(stack);
	if (save)
		new_move(moves, "sa");
}

void	sb(t_stack **stack, t_moves **moves, int save)
{
	swap(stack);
	if (save)
		new_move(moves, "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_moves **moves, int save)
{
	swap(stack_a);
	swap(stack_b);
	if (save)
		new_move(moves, "ss");
}
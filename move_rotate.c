/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramandri <ramandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 03:48:35 by ramandri          #+#    #+#             */
/*   Updated: 2026/05/11 19:22:43 by ramandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	stack_add_back(stack, tmp);
}

void	ra(t_stack **stack, t_moves **moves, int save)
{
	rotate(stack);
	if (save)
		new_move(moves, "ra");
}

void	rb(t_stack **stack, t_moves **moves, int save)
{
	rotate(stack);
	if (save)
		new_move(moves, "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_moves **moves, int save)
{
	rotate(stack_a);
	rotate(stack_b);
	if (save)
		new_move(moves, "rr");
}

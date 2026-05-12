/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramandri <ramandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 04:23:32 by ramandri          #+#    #+#             */
/*   Updated: 2026/05/10 10:21:01 by ramandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_elem;
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_elem = stack_last(*stack);
	if (!last_elem)
		return ;
	tmp = *stack;
	while (tmp && tmp->next != last_elem)
		tmp = tmp->next;
	tmp->next = NULL;
	stack_add_front(stack, last_elem);
}

void	rra(t_stack **stack, t_moves **moves, int save)
{
	reverse_rotate(stack);
	if (save)
		new_move(moves, "rra");
}

void	rrb(t_stack **stack, t_moves **moves, int save)
{
	reverse_rotate(stack);
	if (save)
		new_move(moves, "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_moves **moves, int save)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (save)
		new_move(moves, "rrr");
}

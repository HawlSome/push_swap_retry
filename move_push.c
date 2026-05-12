/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:55:54 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 02:57:36 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!from || !*from)
		return ;
	node = *from;
	*from = (*from)->next;
	node->next = NULL;
	stack_add_front(to, node);
}

void	pa(t_stack **a, t_stack **b, t_moves **moves, int save)
{
	push(b, a);
	if (save)
		new_move(moves, "pa");
}

void	pb(t_stack **a, t_stack **b, t_moves **moves, int save)
{
	push(a, b);
	if (save)
		new_move(moves, "pb");
}

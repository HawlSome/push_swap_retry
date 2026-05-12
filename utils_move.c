/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:00:12 by varandri          #+#    #+#             */
/*   Updated: 2026/05/10 10:23:20 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_moves	*move_last(t_moves *move)
{
	while (move && move->next)
		move = move->next;
	return (move);
}

t_moves	*new_move_node(char *move_name)
{
	t_moves	*move_node;

	if (!move_name)
		return (NULL);
	move_node = (t_moves *)malloc(sizeof(t_moves));
	if (!move_node)
		return (NULL);
	move_node->name = move_name;
	move_node->next = NULL;
	return (move_node);
}

size_t	size_moves(t_moves *moves)
{
	size_t	size;

	size = 0;
	while (moves)
	{
		size ++;
		moves = moves->next;
	}
	return (size);
}

void	move_add_front(t_moves **moves, t_moves *node)
{
	if (!moves || !node)
		return ;
	node->next = *moves;
	*moves = node;
}

void	move_add_back(t_moves **moves,	t_moves	*node)
{
	t_moves	*last_elem;

	if (!moves || !node)
		return ;
	if (!*moves)
	{
		*moves = node;
		return ;
	}
	last_elem = move_last(*moves);
	last_elem->next = node;
}

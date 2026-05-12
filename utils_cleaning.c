/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 22:52:40 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 03:00:19 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack	**stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	while (*stack)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

void	moves_clear(t_moves	**moves)
{
	t_moves	*current;

	if (!moves)
		return ;
	while (*moves)
	{
		current = *moves;
		*moves = (*moves)->next;
		free(current);
	}
}

void	flags_clear(t_flags **flags)
{
	t_flags	*current;

	if (!flags)
		return ;
	while (*flags)
	{
		current = *flags;
		*flags = (*flags)->next;
		free(current);
	}
}

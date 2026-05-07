/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:26:45 by varandri          #+#    #+#             */
/*   Updated: 2026/05/07 16:37:32 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	size_stack(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size ++;
		stack = stack->next;
	}
	return size;
}
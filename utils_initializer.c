/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 02:33:39 by varandri          #+#    #+#             */
/*   Updated: 2026/05/09 04:30:16 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_flag(t_flags **flag, char *algo, int is_adaptive)
{
	t_flags	*flag_node;

	flag_node = new_flag_node(algo, is_adaptive);
	if (!flag_node)
		return ;
	flag_add_back(flag, flag_node);
}

void	new_stack(t_stack **stack, int value)
{
	t_stack	*stack_node;

	stack_node = new_stack_node(value);
	if (!stack_node)
		return ;
	stack_add_back(stack, stack_node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:40:07 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 15:04:41 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	execute_moves_1(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	if (!ft_strcmp(moves, "pa"))
		pa(stack_a, stack_b, NULL, 0);
	else if (!ft_strcmp(moves, "pb"))
		pb(stack_a, stack_b, NULL, 0);
	else if (!ft_strcmp(moves, "ra"))
		ra(stack_a, NULL, 0);
	else if (!ft_strcmp(moves, "rb"))
		rb(stack_b, NULL, 0);
	else if (!ft_strcmp(moves, "rr"))
		rr(stack_a, stack_b, NULL, 0);
	else
		return (0);
	return (1);
}

int	execute_moves_2(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	if (!ft_strcmp(moves, "rra"))
		rra(stack_a, NULL, 0);
	else if (!ft_strcmp(moves, "rrb"))
		rrb(stack_b, NULL, 0);
	else if (!ft_strcmp(moves, "rrr"))
		rrr(stack_a, stack_b, NULL, 0);
	else if (!ft_strcmp(moves, "sa"))
		sa(stack_a, NULL, 0);
	else if (!ft_strcmp(moves, "sb"))
		sb(stack_b, NULL, 0);
	else if (!ft_strcmp(moves, "ss"))
		ss(stack_a, stack_b, NULL, 0);
	else
	{
		ft_printf(2, "Error\n");
		return (0);
	}
	return (1);
}

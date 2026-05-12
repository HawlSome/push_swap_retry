/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:28:16 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 03:00:34 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_adaptive(t_stack **stack_a, t_stack **stack_b, t_moves **moves,
			t_flags **flags)
{
	float	disorder;

	disorder = compute_disorder(*stack_a);
	if (disorder < 0.2f)
	{
		algo_simple(stack_a, stack_b, moves);
		new_flag(flags, "O(n^2)", 1);
	}
	else if (disorder >= 0.2f && disorder < 0.5f)
	{
		algo_medium(stack_a, stack_b, moves);
		new_flag(flags, "O(n√n)", 1);
	}
	else
	{
		algo_complex(stack_a, stack_b, moves);
		new_flag(flags, "O(nlogn)", 1);
	}
}

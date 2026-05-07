/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_disorder_metric.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:46:39 by varandri          #+#    #+#             */
/*   Updated: 2026/05/07 17:13:28 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*next_a;

	if (!a)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	while (a)
	{
		next_a = a->next;
		while (next_a)
		{
			total_pairs ++;
			if (a->value > next_a->value)
				mistakes ++;
			next_a = next_a->next;
		}
		a = a->next;
	}
	return (mistakes / total_pairs);
}

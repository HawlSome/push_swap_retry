/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_disorder_metric.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramandri <ramandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:46:39 by ramandri          #+#    #+#             */
/*   Updated: 2026/05/12 02:57:56 by ramandri         ###   ########.fr       */
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
	if (!total_pairs)
		return ((float)0);
	return ((float)mistakes / (float)total_pairs);
}

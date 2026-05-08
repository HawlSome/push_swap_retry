/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:29:09 by varandri          #+#    #+#             */
/*   Updated: 2026/05/08 17:06:33 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verif_clone(char **clean_input)
{
	size_t	current;
	size_t	next;

	current = 0;
	while (clean_input[current])
	{
		next = current + 1;
		while(clean_input[next])
		{
			if (is_clone(clean_input[current], clean_input[next]))
				return (0);
			next++;
		}
		current++;
	}
}
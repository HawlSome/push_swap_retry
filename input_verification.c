/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:29:09 by varandri          #+#    #+#             */
/*   Updated: 2026/05/09 04:24:20 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verif_flow(char **clean_input)
{
	int	i;

	i = 0;
	while (clean_input[i])
	{
		if (is_over_underlow(clean_input[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	verif_clone(char **clean_input)
{
	size_t	current;
	size_t	next;

	current = 0;
	while (clean_input[current])
	{
		next = current + 1;
		while (clean_input[next])
		{
			if (is_clone(clean_input[current], clean_input[next]))
				return (0);
			next++;
		}
		current++;
	}
	return (1);
}

static int	verif_odd(char **clean_input)
{
	int	i;

	i = 0;
	while (clean_input[i])
	{
		if (!is_str_int(clean_input[i]) && !is_valid_flag(clean_input[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	elem_count(char **clean_input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (clean_input[i])
	{
		if (is_str_int(clean_input[i]))
			count ++;
		i++;
	}
	if (!count)
		return (count);
	return (1);
}

int	verif(char **clean_input)
{
	if (!verif_flow(clean_input))
		return (0);
	if (!verif_clone(clean_input))
		return (0);
	if (!verif_odd(clean_input))
		return (0);
	if (!elem_count(clean_input))
		return (0);
	return (1);
}

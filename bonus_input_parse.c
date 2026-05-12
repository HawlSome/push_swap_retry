/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_input_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:00:10 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 14:31:12 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static void	fill_stack(char **clean_input, t_stack **stack)
{
	int	i;

	i = 0;
	while (clean_input[i])
	{
		if (is_str_int(clean_input[i]))
			new_stack(stack, ft_atoi(clean_input[i]));
		i++;
	}
}

static int	bonus_verif_flow(char **clean_input)
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

static int	bonus_verif_clone(char **clean_input)
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

static int	bonus_verif_int(char **clean_input)
{
	size_t	i;

	i = 0;
	while (clean_input && clean_input[i])
	{
		if (!is_str_int(clean_input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	bonu_parse(int argc, char **argv, t_stack **a)
{
	char	*argv_joined;
	char	**clean_input;

	if (!argv || !*argv)
		return (0);
	argv_joined = ft_strjoin((size_t)(argc - 1), argv + 1, " ");
	if (!argv_joined || !*argv_joined)
	{
		free(argv_joined);
		return (0);
	}
	clean_input = ft_split(argv_joined);
	free(argv_joined);
	if (!clean_input || !*clean_input || !bonus_verif_flow(clean_input)
		|| !bonus_verif_int(clean_input) || !bonus_verif_clone(clean_input))
	{
		free_2d(clean_input);
		return (0);
	}
	fill_stack(clean_input, a);
	free_2d(clean_input);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 05:59:12 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 13:45:10 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_flag(char **clean_input, t_flags **flags)
{
	int	i;

	i = 0;
	while (clean_input[i])
	{
		if (!ft_strcmp(clean_input[i], "--adaptive"))
			new_flag(flags, "adaptive", 1);
		if (!ft_strcmp(clean_input[i], "--bench"))
			new_flag(flags, "bench", 0);
		if (!ft_strcmp(clean_input[i], "--simple"))
			new_flag(flags, "simple", 0);
		if (!ft_strcmp(clean_input[i], "--medium"))
			new_flag(flags, "medium", 0);
		if (!ft_strcmp(clean_input[i], "--complex"))
			new_flag(flags, "complex", 0);
		i++;
	}
}

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

int	parse(int argc, char **argv, t_stack **a, t_flags **flags)
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
	if (!clean_input || !verif(clean_input))
	{
		free_2d(clean_input);
		return (0);
	}
	fill_flag(clean_input, flags);
	fill_stack(clean_input, a);
	free_2d(clean_input);
	return (1);
}

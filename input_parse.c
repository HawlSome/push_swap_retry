/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 05:59:12 by varandri          #+#    #+#             */
/*   Updated: 2026/05/08 16:55:07 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int argc, char **argv, t_stack **a, t_flags **flags)
{
	char	*argv_joined;
	char	**clean_input;

	if (!argv || !*argv)
		return ;
	argv_joined = ft_strjoin(argc - 1, argv + 1, " ");
	if (!argv_joined)
		return (0);
	clean_input = ft_split(argv_joined);
	free(argv_joined);
	if (!clean_input)
		return 0;
}
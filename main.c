/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:11:54 by varandri          #+#    #+#             */
/*   Updated: 2026/05/11 19:48:13 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_moves		*moves;
	t_flags		*flags;

	if (argc <= 1)
		return (0);
	a = NULL;
	b = NULL;
	moves = NULL;
	flags = NULL;
	if (!parse(argc, argv, &a, &flags))
	{
		ft_printf(2, "Error");
		return (0);
	}
	algo_medium(&a, &b, &moves);
	while (moves)
	{
		ft_printf(1, "%s\n", moves->name);
		moves = moves->next;
	}
	return (0);
}

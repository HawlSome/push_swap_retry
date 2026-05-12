/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:11:54 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 03:14:53 by varandri         ###   ########.fr       */
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
		ft_printf(2, "Error\n");
		return (0);
	}
	push_swap(&a, &b, &moves, &flags);
	stack_clear(&a);
	stack_clear(&b);
	flags_clear(&flags);
	moves_clear(&moves);
	return (0);
}

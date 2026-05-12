/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_execute_chechker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:48:01 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 12:48:21 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static void	execute_moves(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	if (!moves || !*moves)
		return ;
	if (!ft_strcmp(moves, "pa"))
		pa(stack_a, stack_b, NULL, 0);
	if (!ft_strcmp(moves, "pb"))
		pb(stack_a, stack_b, NULL, 0);
	if (!ft_strcmp(moves, "ra"))
		ra(stack_a, NULL, 0);
	if (!ft_strcmp(moves, "rb"))
		rb(stack_b, NULL, 0);
	if (!ft_strcmp(moves, "rr"))
		rr(stack_a, stack_b, NULL, 0);
	if (!ft_strcmp(moves, "rra"))
		rra(stack_a, NULL, 0);
	if (!ft_strcmp(moves, "rrb"))
		rrb(stack_b, NULL, 0);
	if (!ft_strcmp(moves, "rrr"))
		rrr(stack_a, stack_b, NULL, 0);
	if (!ft_strcmp(moves, "sa"))
		sa(stack_a, NULL, 0);
	if (!ft_strcmp(moves, "sb"))
		sb(stack_b, NULL, 0);
	if (!ft_strcmp(moves, "ss"))
		ss(stack_a, stack_b, NULL, 0);
}

static void	show_result(t_stack *stack_a)
{
	float	disorder;

	disorder = compute_disorder(stack_a);
	if (disorder < 1e-6f)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
}

void	checker(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	char 	*moves;
	
	if (argc <= 1)
		return ;
	stack_a = NULL;
	if (!bonu_parse(argc, argv, &stack_a))
	{
		ft_printf(2, "Error\n");
		return ;
	}
	while ((moves = get_next_line(1)) != NULL)
	{
		execute_moves(&stack_a, &stack_b, moves);
		free(moves);
	}
	get_next_line(-1);
	show_result(stack_a);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return ;
}
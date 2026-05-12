/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:48:01 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 15:19:15 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static void	trip_moves(char *moves)
{
	size_t	len_moves;

	if (!moves || !*moves)
		return ;
	len_moves = ft_strlen(moves);
	if (len_moves > 0 && moves[len_moves - 1] == '\n')
		moves[len_moves - 1] = '\0';
}

static int	execute_moves(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	int	executed;

	if (!moves || !*moves)
		return (0);
	trip_moves(moves);
	executed = execute_moves_1(stack_a, stack_b, moves);
	if (!executed)
		executed = execute_moves_2(stack_a, stack_b, moves);
	return (executed);
}

static void	show_result(t_stack *stack_a)
{
	float	disorder;

	if (!stack_a)
		return ;
	disorder = compute_disorder(stack_a);
	if (disorder < 1e-6f)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
}

static void	fetch_and_execute(t_stack **stack_a, t_stack **stack_b,
			int *executed)
{
	char	*moves;

	moves = get_next_line(0);
	while (moves != NULL)
	{
		*executed = execute_moves(stack_a, stack_b, moves);
		free(moves);
		if (!*executed)
			break ;
		moves = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		executed;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	executed = 1;
	if (!bonu_parse(argc, argv, &stack_a))
	{
		ft_printf(2, "Error\n");
		return (0);
	}
	fetch_and_execute(&stack_a, &stack_b, &executed);
	if (executed)
		show_result(stack_a);
	get_next_line(-1);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}

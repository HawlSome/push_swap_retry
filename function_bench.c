/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 00:02:01 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 02:44:54 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_sepcific_move(t_moves *moves, char *name)
{
	int	count;

	if (!name)
		return (0);
	count = 0;
	while (moves)
	{
		if (!ft_strcmp(moves->name, name))
			count ++;
		moves = moves->next;
	}
	return (count);
}

static void	print_strategy(t_flags *flag)
{
	if (flag->is_adaptive)
	{
		ft_printf(2, "Adaptive / ");
		ft_printf(2, "%s\n", flag->algo);
		return ;
	}
	if (!ft_strcmp(flag->algo, "simple"))
		ft_printf(2, "Simple / O(n^2)\n");
	if (!ft_strcmp(flag->algo, "medium"))
		ft_printf(2, "Medium / O(n√n)\n");
	if (!ft_strcmp(flag->algo, "complex"))
		ft_printf(2, "Complex / O(nlogn)\n");
}

void	bench_mark(float disorder, t_flags **flags, t_moves **moves)
{
	t_flags	*flag;

	if (!flags || !*flags)
		return ;
	flag = get_executable_flag(*flags);
	ft_printf(2, "[bench] disorder:\t %f%%\n", (float)(disorder * 100));
	ft_printf(2, "[bench] strategy:\t");
	print_strategy(flag);
	ft_printf(2, "[bench] total_ops:\t%i\n", (int)size_moves(*moves));
	ft_printf(2, "[bench] sa:\t%i\t", count_sepcific_move(*moves, "sa"));
	ft_printf(2, "sb:\t%i\t", count_sepcific_move(*moves, "sb"));
	ft_printf(2, "pa:\t%i\t", count_sepcific_move(*moves, "pa"));
	ft_printf(2, "ss:\t%i\t", count_sepcific_move(*moves, "ss"));
	ft_printf(2, "pb:\t%i\n", count_sepcific_move(*moves, "pb"));
	ft_printf(2, "[bench] ra:\t%i\t", count_sepcific_move(*moves, "ra"));
	ft_printf(2, "rb:\t%i\t", count_sepcific_move(*moves, "rb"));
	ft_printf(2, "rr:\t%i\t", count_sepcific_move(*moves, "rr"));
	ft_printf(2, "rra:\t%i\t", count_sepcific_move(*moves, "rra"));
	ft_printf(2, "rrb:\t%i\t", count_sepcific_move(*moves, "rrb"));
	ft_printf(2, "rrr:\t%i\n", count_sepcific_move(*moves, "rrr"));
}

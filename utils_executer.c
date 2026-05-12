/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 01:31:31 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 02:58:44 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_executable_flag(t_flags *flag)
{
	if (ft_strcmp(flag->algo, "bench"))
		return (1);
	return (0);
}

t_flags	*get_executable_flag(t_flags *flag)
{
	t_flags	*executable_flag;

	executable_flag = NULL;
	while (flag)
	{
		if (is_executable_flag(flag))
			executable_flag = flag;
		flag = flag->next;
	}
	return (executable_flag);
}

int	is_elem_in_flags(t_flags *flags, char *str)
{
	if (!str)
		return (0);
	while (flags)
	{
		if (!ft_strcmp(flags->algo, str))
			return (1);
		flags = flags->next;
	}
	return (0);
}

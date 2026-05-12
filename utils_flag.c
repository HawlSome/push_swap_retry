/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 07:09:39 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 00:06:30 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flags	*flag_last(t_flags *flag)
{
	while (flag && flag->next)
		flag = flag->next;
	return (flag);
}

t_flags	*new_flag_node(char *algo, int is_adaptive)
{
	t_flags	*flag;

	if (!algo)
		return (NULL);
	flag = (t_flags *)malloc(sizeof(t_flags));
	if (!flag)
		return (NULL);
	flag->algo = algo;
	flag->is_adaptive = is_adaptive;
	flag->next = NULL;
	return (flag);
}

size_t	size_flag(t_flags *flag)
{
	size_t	size;

	size = 0;
	while (flag)
	{
		size ++;
		flag = flag->next;
	}
	return (size);
}

void	flag_add_front(t_flags **flag, t_flags *node)
{
	if (!flag || !node)
		return ;
	node->next = *flag;
	*flag = node;
}

void	flag_add_back(t_flags **flag, t_flags *node)
{
	t_flags	*last_elem;

	if (!flag || !node)
		return ;
	if (!*flag)
	{
		*flag = node;
		return ;
	}
	last_elem = flag_last(*flag);
	last_elem->next = node;
}

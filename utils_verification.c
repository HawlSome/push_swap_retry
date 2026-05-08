/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:38:31 by varandri          #+#    #+#             */
/*   Updated: 2026/05/08 17:12:30 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_str_int(char *str)
{
	
}

int	is_clone(char *current, char *next)
{
	if ((is_str_int(current) && is_str_int(next))
		&& ft_atoi(current) == ft_atoi(next))
		return (1);
	return (0);
}
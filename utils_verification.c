/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:38:31 by varandri          #+#    #+#             */
/*   Updated: 2026/05/09 04:29:59 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *str_1, char *str_2)
{
	int	i;

	if (!str_1 && !str_2)
		return (0);
	if (!str_1)
		return (-(unsigned char)str_2[0]);
	if (!str_2)
		return (-(unsigned char)str_1[0]);
	i = 0;
	while ((unsigned char)str_1[i] && (unsigned char)str_2[i])
	{
		if ((unsigned char)str_1[i] != (unsigned char)str_2[i])
			return ((unsigned char)str_1[i] - (unsigned char)str_2[i]);
		i ++;
	}
	return ((unsigned char)str_1[i] - (unsigned char)str_2[i]);
}

int	is_clone(char *current, char *next)
{
	if ((is_str_int(current) && is_str_int(next))
		&& ft_atoi(current) == ft_atoi(next))
		return (1);
	return (0);
}

int	is_valid_flag(char *input)
{
	int	res;

	res = 0;
	if (!ft_strcmp(input, "--adaptive"))
		res = 1;
	if (!ft_strcmp(input, "--bench"))
		res = 1;
	if (!ft_strcmp(input, "--simple"))
		res = 1;
	if (!ft_strcmp(input, "--medium"))
		res = 1;
	if (!ft_strcmp(input, "--complex"))
		res = 1;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:35:11 by varandri          #+#    #+#             */
/*   Updated: 2026/05/09 04:29:32 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || sign == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(sign * nbr));
}

int	is_over_underlow(char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || sign == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (sign == 1 && nbr > 2147483647LL)
			return (1);
		if (sign == -1 && nbr > 2147483648LL)
			return (1);
		i++;
	}
	return (0);
}

int	is_str_int(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	is_str_int_present(char **arr_str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (arr_str[i])
	{
		if (is_str_int(arr_str[i]))
			count++;
		i++;
	}
	if (count)
		return (1);
	return (0);
}

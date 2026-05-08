/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:29:23 by varandri          #+#    #+#             */
/*   Updated: 2026/05/08 15:05:29 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_delim(char c)
{
	if (c == 32 || c >= 9 && c <= 13)
		return (1);
	return (0);
}

static size_t	len_block(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] && is_delim(str[i]))
		i++;
	while (str[i + len] && !is_delim(str[i + len]))
		len ++;
	return (len);
}

static size_t	count_block(char *str)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		len = 0;
		while (str[i + len] && !is_delim(str[i + len]))
			len ++;
		if (!len)
			i++;
		else
		{
			count++;
			i = i + len;
		}
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**split_str;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	split_str = (char **)ft_calloc(count_block(str) + 1, sizeof(char *));
	if (!split_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_block(str))
	{
		while (str[j] && is_delim(str[j]))
			j++;
		split_str[i] = ft_substr(str, j, len_block(&str[j]));
		if (!split_str[i])
		{
			free_2d(split_str);
			return (NULL);
		}
		j += len_block(&str[j]);
		i++;
	}
	return (split_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:29:23 by varandri          #+#    #+#             */
/*   Updated: 2026/05/08 14:06:48 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	len_block(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while(str[i] && (str[i] == 32 || str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i + len] && !(str[i + len] == 32 || str[i + len] >=9
			&& str[i + len] <= 13))
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
		while(str[i + len] && !(str[i + len] == 32 || str[i + len] >=9
			&& str[i + len] <= 13))
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
	char	*split_str;
	size_t	i;
	size_t	j;
	
	if (!str)
		return (NULL);
	split_str = (char **)ft_calloc(0,0);
}
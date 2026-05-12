/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_get_next_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:15:12 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 15:08:56 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static void	gnl_memmove(char *str_1, char *str_2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;

	if (str_1 == str_2 || n == 0)
		return ;
	s_1 = (unsigned char *)str_1;
	s_2 = (unsigned char *)str_2;
	if (s_1 < s_2)
	{
		while (n--)
			*(s_1++) = *(s_2++);
	}
	if (s_1 > s_2)
	{
		while (n)
		{
			s_1[n - 1] = s_2[n - 1];
			n--;
		}
	}
}

void	*gnl_strjoin(char *stash, char *buff)
{
	char	*new_str;
	size_t	stash_len;
	size_t	buff_line;

	if (!stash && !buff)
		return (NULL);
	stash_len = ft_strlen(stash);
	buff_line = ft_strlen(buff);
	new_str = (char *)ft_calloc((stash_len + buff_line + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	if (stash)
		gnl_memmove(new_str, stash, stash_len);
	if (buff)
		gnl_memmove(new_str + stash_len, buff, buff_line);
	return (new_str);
}

char	*gnl_substr(char *s, size_t start, size_t sub_len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (sub_len >= ft_strlen(s + start))
		sub_len = ft_strlen(s + start);
	sub = (char *)ft_calloc(sub_len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}

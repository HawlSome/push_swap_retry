/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:05:25 by varandri          #+#    #+#             */
/*   Updated: 2026/05/08 22:00:35 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
		((unsigned char *)res)[i++] = (unsigned char)0;
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*sb_str;
	size_t	i;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	sb_str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!sb_str)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		sb_str[i] = str[start + i];
		i++;
	}
	return (sb_str);
}

void	free_2d(char **arr_str)
{
	size_t	i;

	i = 0;
	while (arr_str && arr_str[i])
		free(arr_str[i++]);
	free(arr_str);
}

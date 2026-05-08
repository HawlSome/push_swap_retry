/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:48:04 by varandri          #+#    #+#             */
/*   Updated: 2026/05/08 13:08:58 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	total_len(size_t argc, char **argv, char *delim)
{
	size_t	i;
	size_t	len;
	size_t	delim_len;	

	i = 0;
	len = 0;
	delim_len = ft_strlen(delim);
	while(i < argc)
	{
		len = ft_strlen(argv[i]);
		if (i != argc - 1)
			len += delim_len;
		i++;
	}
	len++;
	return (len);
}

static	size_t	fill_new_str(char *new_str, size_t argc,
					char **argv, char *delim)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			new_str[k] = argv[i][j];
			k++;
			j++;
		}
	}
}

char	*ft_strjoin(size_t argc, char **argv, char *delim)
{
	char	*new_str;

	if (!delim)
		return (NULL);
	new_str = (char *)ft_calloc(total_len(argc, argv, delim), sizeof(char));
	if (!new_str)
		return (NULL);
	
}
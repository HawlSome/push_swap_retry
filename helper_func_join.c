/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:48:04 by varandri          #+#    #+#             */
/*   Updated: 2026/05/09 04:22:58 by varandri         ###   ########.fr       */
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
	while (i < argc)
	{
		if (!argv[i])
		{
			i++;
			continue ;
		}
		len += ft_strlen(argv[i]);
		if (i != argc - 1)
			len += delim_len;
		i++;
	}
	len++;
	return (len);
}

static	void	add_delim(size_t *k, char *new_str, char *delim)
{
	size_t	i;

	i = 0;
	while (delim[i])
	{
		new_str[*k] = delim[i];
		i ++;
		*k = *k + 1;
	}
}

static	void	fill_new_str(char *new_str, size_t argc,
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
		if (!argv[i])
		{
			i++;
			continue ;
		}
		while (argv[i][j])
		{
			new_str[k] = argv[i][j];
			k++;
			j++;
		}
		if (i != argc - 1)
			add_delim(&k, new_str, delim);
		i++;
	}
}

char	*ft_strjoin(size_t argc, char **argv, char *delim)
{
	char	*new_str;

	if (!delim || !argv)
		return (NULL);
	new_str = (char *)ft_calloc(total_len(argc, argv, delim), sizeof(char));
	if (!new_str)
		return (NULL);
	fill_new_str(new_str, argc, argv, delim);
	return (new_str);
}

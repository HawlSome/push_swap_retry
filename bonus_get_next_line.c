/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 10:01:37 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 14:32:47 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static int	find_endl(char *stash)
{
	size_t	i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_all_lines(int fd, char *stash)
{
	ssize_t	byte_read;
	char	*temp;
	char	*buff;

	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !find_endl(stash))
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[byte_read] = '\0';
		temp = gnl_strjoin(stash, buff);
		free(stash);
		stash = temp;
	}
	free(buff);
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*extracted;
	char	*leftover;
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	extracted = gnl_substr(*stash, 0, i);
	leftover = gnl_substr(*stash, i, ft_strlen(*stash + i));
	free(*stash);
	*stash = leftover;
	return (extracted);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = get_all_lines(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

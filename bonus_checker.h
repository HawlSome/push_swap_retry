/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:51:03 by varandri          #+#    #+#             */
/*   Updated: 2026/05/12 12:54:01 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BONUS_CHECKER_H
# define BONUS_CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "push_swap.h"
	
void	*gnl_strjoin(char *stash, char *buff);
char	*gnl_substr(char *s, size_t start, size_t sub_len);
int		bonu_parse(int argc, char **argv, t_stack **a);
char	*get_next_line(int	fd);

#endif
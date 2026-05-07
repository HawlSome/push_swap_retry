

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "./ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				value;
	long			index;
	struct s_stack	*next;
} t_stack;

typedef struct s_move
{
	char			*name;
	struct s_move	*next;
} t_moves;

typedef	struct s_flags
{
	char			*algo;
	int				is_adaptive;
	struct s_flags	*next;
} t_flags;

size_t	size_stack(t_stack *stack);

#endif
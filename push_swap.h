#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	long			index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_move
{
	char			*name;
	struct s_move	*next;
}	t_moves;

typedef struct s_flags
{
	char			*algo;
	int				is_adaptive;
	struct s_flags	*next;
}	t_flags;

size_t	size_stack(t_stack *stack);
void	stack_add_front(t_stack **stack, t_stack *node);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *node);


void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
char	*ft_substr(char *str, unsigned int start, size_t len);


#endif
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

t_stack	*new_stack_node(int value);
size_t	size_stack(t_stack *stack);
void	stack_add_front(t_stack **stack, t_stack *node);
void	stack_add_back(t_stack **stack, t_stack *node);
void	new_stack(t_stack **stack, int value);

t_flags	*new_flag_node(char *algo, int is_adaptive);
size_t	size_flag(t_flags *flag);
void	flag_add_front(t_flags **flag, t_flags *node);
void	flag_add_back(t_flags **flag, t_flags *node);
void	new_flag(t_flags **flag, char *algo, int is_adaptive);

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
char	*ft_substr(char *str, unsigned int start, size_t len);
void	free_2d(char **arr_str);
char	*ft_strjoin(size_t argc, char **argv, char *delim);
char	**ft_split(char *str);
int		ft_strcmp(char *str_1, char *str_2);

int		ft_atoi(char *str);
int		is_over_underlow(char *str);
int		is_str_int(char *str);
int		is_str_int_present(char **arr_str);

int		is_clone(char *current, char *next);
int		is_valid_flag(char *input);
int		verif(char **clean_input);
int		parse(int argc, char **argv, t_stack **a, t_flags **flags);

#endif

NAME = push_swap

BONUS_NAME = checker

PRINTF_DIR = ft_printf

SRC = helper_func_split.c \
		algo_least_five.c \
		utils_algo.c \
		algo_medium.c \
		move_push.c \
		utils_cleaning.c \
		utils_flag.c \
		function_bench.c \
		algo_complex.c \
		utils_stack.c \
		function_disorder_metric.c \
		utils_str.c \
		utils_executer.c \
		algo_simple.c \
		utils_verification.c \
		utils_initializer.c \
		move_rotate.c \
		executer_push_swap.c \
		move_reverse_rotate.c \
		input_parse.c \
		utils_move.c \
		helper_func_join.c \
		utils_int.c \
		move_swap.c \
		algo_adaptive.c \
		input_verification.c

MAIN_SRC = 	main.c


BONUS_SRC = bonus_input_parse.c \
			bonus_get_next_line.c \
			bonus_utils_checker.c \
			bonus_checker.c \
			bonus_utils_get_next_line.c

OBJ = $(SRC:.c=.o) $(MAIN_SRC:.c=.o)

BONUS_OBJ = $(SRC:.c=.o) $(BONUS_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

bonus: $(BONUS_NAME) 

$(NAME): $(OBJ) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(BONUS_NAME): $(BONUS_OBJ) $(PRINTF)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(PRINTF) -o $(BONUS_NAME)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@rm -rf $(OBJ)


%.o: %.c push_swap.h bonus_checker.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(PRINTF_DIR)
	@rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@rm -rf $(NAME) $(BONUS_NAME)

re: fclean all


.PHONY: all clean fclean re
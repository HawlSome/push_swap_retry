# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramandri <ramandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/27 23:50:55 by varandri          #+#    #+#              #
#    Updated: 2026/05/07 12:00:47 by ramandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_put_str.c ft_put_nbr.c ft_put_float.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

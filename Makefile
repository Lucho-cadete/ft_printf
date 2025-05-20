# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 13:01:11 by luimarti          #+#    #+#              #
#    Updated: 2025/05/19 21:48:02 by luimarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

CC=cc
# CFLAGS=-Wall -Wextra -Werror

INCLUDES = -Ilibft

EXEC = main

PRINTF_SRC= ft_printf.c\
		data_filter.c\
		handlers_dec.c\
		handlers_hex.c\
		handler_unsgined_int.c

LIBFT_SRC = \
	libft/ft_itoa.c\
	libft/ft_strlen.c\
	libft/ft_calloc.c

SRC = $(PRINTF_SRC) $(LIBFT_SRC)

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re exec

all: $(NAME)

$(NAME):$(OBJ)
	ar rcsUu $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

exec: all
	$(CC)  main.c $(NAME) $(INCLUDES) -o $(EXEC)

clean:
	rm -f $(OBJ)
	@echo "\033[1;31m🧹 Deleted\033[0m"

fclean: clean
	rm -f $(NAME) $(EXEC)
	@echo "\033[1;31m🗑️ All deleted\033[0m"

re: fclean all
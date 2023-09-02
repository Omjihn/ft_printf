# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 13:11:49 by gbricot           #+#    #+#              #
#    Updated: 2023/09/02 14:13:44 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/ft_printf.c \
	src/ft_exec.c \
	src/ft_get_flags_info.c \
	src/ft_print_cs.c \
	src/utils.c \
	src/ft_utils_2.c 

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

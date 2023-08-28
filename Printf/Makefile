# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 13:32:39 by gbricot           #+#    #+#              #
#    Updated: 2023/03/06 15:47:26 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MY_SOURCES = ft_printf.c ft_put_adress.c ft_put_char_str.c \
	     ft_putnbr_base.c ft_put_nbr.c ft_itoa.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS)
	ar cr $(NAME) $(MY_OBJECTS)

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

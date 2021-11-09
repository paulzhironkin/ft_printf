# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 16:18:28 by latahbah          #+#    #+#              #
#    Updated: 2021/11/09 22:40:06 by latahbah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST =	ft_printf.c	ft_itoa.c		ft_strdup.c \
		ft_strlen.c		print_char.c \
		print_int.c	print_pointer.c	print_str.c \
		ft_putnbr_base.c

OBJ = $(patsubst %.c,%.o,$(LIST))

D_FILES = $(patsubst %.c,%.d,$(LIST))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
	@rm -f $(OBJ) $(D_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean	all

.PHONY: all clean fclean re

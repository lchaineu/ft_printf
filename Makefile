# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 13:46:07 by lchaineu          #+#    #+#              #
#    Updated: 2020/12/21 13:02:04 by lchaineu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Werror -Wall -Wextra

NAME = libftprintf.a

SRC = ft_printf.c \
    parsing.c \
    parsing2.c \
    utils.c \
    utils_2.c \
    utils_3.c \
    convert_d_i.c \
    convert_c.c \
    convert_s.c \
    convert_p.c \
    convert_u_xx.c \
    convert_percent.c \
    answer.c \
    convert_u_xx2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) ft_printf.h
	ar  rc  $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

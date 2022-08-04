# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 13:20:22 by pmeising          #+#    #+#              #
#    Updated: 2022/08/04 20:31:34 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

CC			:= gcc -g

CFLAGS		:= -Werror -Wextra -Wall

RM			:= rm -f

HEADER		:= so_long.h

SRCS		:= main.c ft_hooks.c ./read_map/ft_read_from_map.c \
			./read_map/ft_put_square.c ./error_handling/ft_error.c	\
			./gnl/get_next_line.c ./gnl/get_next_line_utils.c	\

OBJS		:= ${SRCS:.c=.o}

LIBFT = ./libft/libft.a

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	$(LIBFT)
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
			make all -C ./libft

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
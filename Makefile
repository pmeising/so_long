# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 13:20:22 by pmeising          #+#    #+#              #
#    Updated: 2022/08/07 22:01:26 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

CC			:= gcc -g

CFLAGS		:= -Werror -Wextra -Wall

RM			:= rm -f

HEADER		:= so_long.h

MLX_DIR= ./minilibx-linux/

MLX = ./minilibx-linux/libmlx.a

SRCS		:= main.c ft_hooks.c ./read_map/ft_read_from_map.c \
			./read_map/ft_put_square.c ./error_handling/ft_error.c	\
			./movement/ft_movements.c ./error_handling/ft_end_program.c	\

OBJS		:= ${SRCS:.c=.o}

LIBFT = ./libft_lib/libft.a

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	$(LIBFT)
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
			make all -C ./libft_lib

$(MLX):
			make -C $(MLX_DIR)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
			$(CC) $(OBJS) $(LIBFT) $(MLX) -L/usr/X11/lib -lXext -lX11 -o $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
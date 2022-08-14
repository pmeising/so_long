# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 13:20:22 by pmeising          #+#    #+#              #
#    Updated: 2022/08/14 17:01:55 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

BONUS		:= so_long_bonus

CC			:= gcc -g

CFLAGS		:= -Werror -Wextra -Wall -fsanitize=address

RM			:= rm -f

HEADER		:= so_long.h

MLX_DIR= ./minilibx-linux/

MLX = ./minilibx-linux/libmlx.a

SRCS		:= main.c ft_hooks.c ./read_map/ft_read_from_map.c \
			./movement/ft_put_square.c ./error_handling/ft_error.c	\
			./movement/ft_movements.c ./error_handling/ft_close_program.c	\
			./movement/ft_helper.c ./movement/ft_helper_2.c \
			./read_map/ft_map_check.c ./movement/ft_write_steps.c 

B_SRCS		:= ./bonus/main_bonus.c ft_hooks.c ./read_map/ft_read_from_map.c \
			./movement/ft_put_square.c ./error_handling/ft_error.c	\
			./bonus/ft_movements_bonus.c ./error_handling/ft_close_program.c	\
			./movement/ft_helper.c ./bonus/ft_helper_2_bonus.c	./bonus/ft_helper_3.c \
			./bonus/ft_put_square_loop.c ./bonus/ft_put_square_walk.c \
			./bonus/ft_animation.c  ./bonus/ft_villain.c ./bonus/ft_put_square_villain.c \
			./bonus/ft_game_over.c ./read_map/ft_map_check.c ./bonus/ft_bonus_helper.c \
			./bonus/ft_put_flames.c ./bonus/ft_write_steps_bonus.c ./bonus/ft_animate_villain.c \

OBJS		:= ${SRCS:.c=.o}

B_OBJS		:= ${B_SRCS:.c=.o}

LIBFT = ./libft_lib/libft.a

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	$(LIBFT)
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
			make all -C ./libft_lib

$(MLX):
			make -C $(MLX_DIR)

$(BONUS):	$(LIBFT) $(MLX) $(B_OBJS)
			$(CC) $(B_OBJS) $(LIBFT) $(MLX) -L/usr/X11/lib -lXext -lX11 -o $(NAME)


$(NAME):	$(LIBFT) $(MLX) $(OBJS)
			$(CC) $(OBJS) $(LIBFT) $(MLX) -L/usr/X11/lib -lXext -lX11 -o $(NAME)


bonus:		${BONUS}

re:			fclean all

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)
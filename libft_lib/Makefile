# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 23:38:18 by pmeising          #+#    #+#              #
#    Updated: 2022/08/07 09:35:31 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
CFLAGS		:= -Wall -Wextra -Werror
CC 			:= gcc
RM			:= rm -f
AR			:= ar rcs
LIBFT		:= libft.h

SOURCES		:= ./sources/

SRCS	:=	$(SOURCES)ft_atoi.c			\
			$(SOURCES)ft_bzero.c			\
			$(SOURCES)ft_calloc.c			\
			$(SOURCES)ft_isalnum.c		\
			$(SOURCES)ft_isalpha.c		\
			$(SOURCES)ft_isascii.c		\
			$(SOURCES)ft_isdigit.c		\
			$(SOURCES)ft_isprint.c		\
			$(SOURCES)ft_itoa.c			\
			$(SOURCES)ft_memchr.c			\
			$(SOURCES)ft_memcmp.c			\
			$(SOURCES)ft_memcpy.c			\
			$(SOURCES)ft_memmove.c		\
			$(SOURCES)ft_memset.c			\
			$(SOURCES)ft_putchar_fd.c		\
			$(SOURCES)ft_putendl_fd.c		\
			$(SOURCES)ft_putnbr_fd.c		\
			$(SOURCES)ft_putstr_fd.c		\
			$(SOURCES)ft_split.c			\
			$(SOURCES)ft_strchr.c			\
			$(SOURCES)ft_strdup.c			\
			$(SOURCES)ft_striteri.c		\
			$(SOURCES)ft_strjoin.c		\
			$(SOURCES)ft_strlcat.c		\
			$(SOURCES)ft_strlcpy.c		\
			$(SOURCES)ft_strlen.c			\
			$(SOURCES)ft_strmapi.c		\
			$(SOURCES)ft_strncmp.c		\
			$(SOURCES)ft_strnstr.c		\
			$(SOURCES)ft_strrchr.c		\
			$(SOURCES)ft_strtrim.c		\
			$(SOURCES)ft_substr.c			\
			$(SOURCES)ft_tolower.c		\
			$(SOURCES)ft_toupper.c		\
			$(SOURCES)get_next_line.c	\
			$(SOURCES)get_next_line_utils.c	\
			$(SOURCES)ft_hex_func_p.c	\
			$(SOURCES)ft_hex.c			\
			$(SOURCES)ft_itoa_u.c		\
			$(SOURCES)ft_printf.c		\
			$(SOURCES)ft_putperc.c		\
			$(SOURCES)ft_putstr.c		\

SRCBONUS := $(SOURCES)ft_lstnew.c			\
			$(SOURCES)ft_lstadd_front.c	\
			$(SOURCES)ft_lstsize.c		\
			$(SOURCES)ft_lstlast.c		\
			$(SOURCES)ft_lstadd_back.c	\
			$(SOURCES)ft_lstdelone.c		\
			$(SOURCES)ft_lstclear.c		\
			$(SOURCES)ft_lstiter.c		\
			$(SOURCES)ft_lstmap.c

OBJS		:= ${SRCS:.c=.o}

B_OBJS		:= ${SRCBONUS:.c=.o}

.PHONY: bonus all clean fclean re

all:		${NAME}

$(NAME):	${OBJS} ${LIBFT}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${B_OBJS}
			${AR} ${NAME} ${B_OBJS}
			ranlib ${NAME}

%.o: %.c $(LIBFT)
			${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} ${B_OBJS}

fclean:		clean
	${RM} $(NAME)

re:			fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 20:42:34 by rchbouki          #+#    #+#              #
#    Updated: 2023/03/31 16:05:50 by rchbouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f
HEADER = -I ./includes
NAME = push_swap
NAME_BONUS = checker
OBJS = ${SRCS_MAIN:.c=.o}
BONUS_OBJS = ${SRCS_BONUS:.c=.o}
SRCS = big_sort_utils.c \
	check_swap.c \
	operations.c \
	push_swap_utils.c \
	sort_opti.c \
	sort_utils.c \
	stack_sort.c \
	stack_utils.c \
	ft_printf.c \
	ft_printf_utils.c \
	ft_write.c \

SRCS_MAIN = push_swap.c ${SRCS}

SRCS_BONUS = checker.c ${SRCS}

.c.o :
	${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	${CC} ${CFLAGS}  -o ${NAME} ${OBJS}

${NAME_BONUS} : ${BONUS_OBJS}
	${CC} ${CFLAGS} -o ${NAME_BONUS} ${BONUS_OBJS}

all : ${NAME}

bonus : ${NAME_BONUS}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : all clean fclean re

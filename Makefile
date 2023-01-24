# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 17:32:10 by mdorr             #+#    #+#              #
#    Updated: 2023/01/23 17:51:46 by mdorr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c \
			operations.c \
			operations2.c \
			operations3.c \
			utils.c \
			pile_utils.c \
			subset.c \
			easy_sorting.c \
			hard_sorting.c

BONUS	=	checker_src/checker.c \
			checker_src/get_next_line.c \
			checker_src/get_next_line_utils.c \
			operations.c \
			operations2.c \
			operations3.c \
			utils.c \
			pile_utils.c \

NAME	=	./push_swap

BONUS_NAME = ./checker

OBJS	= 	${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

CC	= 	gcc


CFLAGS	= 	-Wall -Wextra -Werror


.c.o:

		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}



all:	${OBJS}
	${CC} ${OBJS} -o ${NAME}

clean:
		rm -f ${OBJS}
		rm -f checker_src/{BONUS_OBJS}


fclean:	clean
		rm -f ${NAME}
		rm -f {BONUS_NAME}

bonus:	${BONUS_OBJS}
	${CC} ${BONUS_OBJS} -o ${BONUS_NAME}

re:	fclean all

.PHONY : 	all clean fclean re

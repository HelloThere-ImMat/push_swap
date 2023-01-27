# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 17:32:10 by mdorr             #+#    #+#              #
#    Updated: 2023/01/27 18:09:59 by mdorr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = obj

BONUS_OBJ_DIR = bonus_obj

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
			checker_src/operations.c \
			checker_src/operations2.c \
			checker_src/operations3.c \
			checker_src/pile_utils.c \
			checker_src/utils.c


NAME	=	./push_swap

BONUS_NAME = ./checker

OBJS	= 	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS	= $(BONUS:.c=.o)

CC	= 	gcc

CFLAGS	= 	-Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS}
	${CC} ${BONUS_OBJS} -o ${BONUS_NAME}

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re

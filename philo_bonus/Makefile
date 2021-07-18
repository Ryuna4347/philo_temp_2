# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 15:57:44 by hyunyoo           #+#    #+#              #
#    Updated: 2021/07/18 15:22:28 by hyunyoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c utils.c utils2.c init.c message.c eat.c forks.c exit.c monitor.c sem.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
LIBS			= -lpthread

NAME			= philo_bonus

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc -g ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

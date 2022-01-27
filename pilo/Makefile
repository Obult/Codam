# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: obult <obult@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/19 12:29:04 by obult         #+#    #+#                  #
#    Updated: 2022/01/22 16:12:12 by obult         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= philo
OBJ			= obj/main.o
CC			= gcc
RM			= rm -f
HEADER		= -I headers/
CFLAGS		= -Wall -Werror -Wextra -fsanitize=address

all:		${NAME}

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) -c $(CFLAGS) $(HEADER) -o $@ $<

clean:
				@${RM} ${OBJ} \
				$(info ************  Pilo Clean)

fclean:		clean
				@${RM} ${NAME} \
				$(info ************  Pilo Removed) \

re:			fclean all

${NAME}:	${OBJ}
				@${CC} -fsanitize=address -o $@ $^ \
				$(info ************  Pilo Ready!)

.PHONY: all clean fclean re libft
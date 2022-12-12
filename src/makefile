# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 13:01:32 by ciclo             #+#    #+#              #
#    Updated: 2022/12/12 19:41:31 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRC = get_next_line.c \
	get_next_line_utils.c \
	main.c

OBJ=$(SRC:.c=.o)

C = gcc

F = -Wall -Werror -Wextra

R = rm -rf

all:

		$(C) $(F) $(SRC) -o $(NAME) && ./$(NAME) txt/fd.txt

clean:

	$(R) $(OBJ)

fclean: clean

	clean $(NAME)
re:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 13:01:32 by ciclo             #+#    #+#              #
#    Updated: 2023/10/25 21:42:06 by Dugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

SRC = get_next_line.c \
	get_next_line_utils.c \
	main.c

OBJ=$(SRC:.c=.o)

C = gcc

F = -Wall -Werror -Wextra

R = rm -rf

all:

		$(C) $(F) $(SRC) -o $(NAME) && ./$(NAME) < txt/fd.txt

clean:

	$(R) $@

fclean:

	rm -rf  $(NAME)

re: fclean all


val:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./$(NAME) < txt/fd.txt

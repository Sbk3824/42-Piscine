# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 22:30:50 by skuntoji          #+#    #+#              #
#    Updated: 2018/07/11 22:34:52 by skuntoji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/main.c srcs/functions.c srcs/functions_more.c srcs/ft_start.c \
	  srcs/ft_check_instructions.c srcs/ft_board.c srcs/ft_optimisations.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -O3 -o $(NAME) $(SRC)
clean:
		/bin/rm -f
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all

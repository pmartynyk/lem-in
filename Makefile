# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 09:38:43 by pmartyny          #+#    #+#              #
#    Updated: 2018/11/12 16:30:51 by pmartyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE = ./src/lem_in.c\
		./src/read.c\
		./src/print.c\
		./src/check.c\
		./src/list_function.c\
		./src/list_function_2.c\
		./src/additional.c\
		./src/find_path.c\
		./src/find_path_1.c\
		./src/move_ants.c




OB = $(SOURCE:%.c=%.o)

all: $(NAME)

%.o:%.c
	@$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OB)
	@make -C libft_printf
	@$(CC) $(OB) libft_printf/libftprintf.a -g -o $(NAME)

clean: 
	@make clean -C libft_printf
	@/bin/rm -f $(OB)

fclean: clean
	@make fclean -C libft_printf
	@/bin/rm -f $(NAME)

re:	fclean all


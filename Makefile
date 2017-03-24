#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 15:40:33 by msymkany          #+#    #+#              #
#    Updated: 2017/03/22 19:34:43 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# checker prog
#NAME_1 = checker
#SRC_1 =
#OBJ_1 = $(SRC_1:.c=.o)

# push_swap prog
NAME_2 = push_swap
SRC_2 = read_stack.c\
		ft_error.c\
		ft_usage.c\

OBJ_2 = $(SRC_2:.c=.o)

#includes
INC = push.h 
INC_OP = -I $(INC) -I $(LIBFT_I) -I $(PRINTF_I)

# compilation
CC = gcc
FL = -g -Wall -Wextra -Werror

# libraries
LIBFT_DIR = ./libft/
LIBFT_I = ./libft/libft.h
PRINTF_I = ./libft/libftprintf.h

all: $(NAME_2)

#$(NAME_1): $(OBJ_1) $(LIBFT_DIR)libft.a:
#		$(CC) $(FL) $(OBJ_1) -o $(NAME_1) -L$(LIBFT_DIR) -lft

$(NAME_2): $(OBJ_2) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJ_2) -o $(NAME_2) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR)

.PHONY: clean fclean re rmtr

clean:
	make clean -C $(LIBFT_DIR)
#	rm -f $(OBJ_1)
	rm -f $(OBJ_2)

fclean: clean
	make fclean -C $(LIBFT_DIR)
#	rm -f $(OBJ_1)
	rm -f $(OBJ_2)

re: fclean all
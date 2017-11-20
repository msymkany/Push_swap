#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 15:40:33 by msymkany          #+#    #+#              #
#    Updated: 2017/04/10 15:26:01 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# checker prog
NAME_1 = checker
SRC_1 = checker.c\
		read_stack.c\
		stack_sorted.c\
		ft_error.c\
		ft_usage.c\
		stack_list.c\
		op_swap.c\
		op_push.c\
		op_rotate.c\
		op_reverse.c\
		debug_option.c\

OBJ_1 = $(SRC_1:.c=.o)

# push_swap prog
NAME_2 = push_swap
SRC_2 = push_swap.c\
		read_stack.c\
		sort_it.c\
		timsort.c\
		stack_sorted.c\
		ft_error.c\
		ft_usage.c\
		stack_list.c\
		op_swap.c\
		op_push.c\
		op_rotate.c\
		op_reverse.c\
		debug_option.c\
		quick_sort.c \

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

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_1) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJ_1) -o $(NAME_1) -L$(LIBFT_DIR) -lft

$(NAME_2): $(OBJ_2) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJ_2) -o $(NAME_2) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR)

.PHONY: clean fclean re rmtr

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ_1)
	rm -f $(OBJ_2)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all
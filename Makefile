# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 15:32:27 by nakoriko          #+#    #+#              #
#    Updated: 2024/08/25 18:01:21 by nakoriko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c ft_big_sort.c ft_calc.c ft_final_sort.c \
	ft_final_stack.c ft_mose_reverse.c ft_mosse.c ft_on_top.c \
	ft_sort.c ft_stack_divide.c ft_stack.c parsing.c utils.c utils_2.c\

OBJ = $(SRCS:.c=.o)

CC = cc -g

CFLAG = -Wall -Wextra -Werror

HEADER = push_swap.h

NAME = push_swap
LIBFT = libft

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C libft/

$(NAME): $(OBJ)
	@$(CC) -g $(OBJ) libft/libft.a libft/ft_printf/libftft_printf.a -o $(NAME)

%.o:%.c $(HEADER)
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	$(MAKE) clean -C libft/

fclean: clean
	@rm -f $(NAME)
	$(MAKE) fclean -C libft/

re: fclean all

.PHONY:  all clean fclean re libft

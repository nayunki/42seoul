# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:03:58 by naki              #+#    #+#              #
#    Updated: 2023/02/22 15:35:15 by naki             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
	greedy.c \
	parsing.c \
	commands.c \
	push_swap.c \
	preprocess.c \
	greedy_utils.c \
	push_swap_utils.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -g3

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	@make -C ./libft all
	$(CC) $(CFLAGS) -o $@ $^ -L ./libft -lft

all : $(NAME)

clean :
	@make -C ./libft clean
	$(RM) $(OBJS)

fclean : clean
	@make -C ./libft clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

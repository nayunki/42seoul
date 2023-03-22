# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:03:58 by naki              #+#    #+#              #
#    Updated: 2023/02/26 11:02:13 by naki             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRCS = \
	greedy.c \
	parsing.c \
	commands.c \
	push_swap.c \
	preprocess.c \
	list_utils.c \
	greedy_utils.c \
	push_swap_utils.c \

SRCS_BONUS = \
	./bonus/parsing_bonus.c \
	./bonus/commands_bonus.c \
	./bonus/push_swap_bonus.c \
	./bonus/list_utils_bonus.c \
	./bonus/get_next_line_bonus.c \
	./bonus/checker_utils_bonus.c \
	./bonus/push_swap_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft all
	$(CC) $(CFLAGS) -o $@ $^ -L ./libft -lft

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@make -C ./libft all
	$(CC) $(CFLAGS) -o $@ $^ -L ./libft -lft

clean :
	@make -C ./libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	@make -C ./libft fclean
	$(RM) $(NAME) $(NAME_BONUS)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:03:58 by naki              #+#    #+#              #
#    Updated: 2023/02/25 16:30:39 by naki             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#NAME_BONUS = checker

SRCS = \
	greedy.c \
	parsing.c \
	commands.c \
	push_swap.c \
	preprocess.c \
	list_utils.c \
	greedy_utils.c \
	push_swap_utils.c \

#SRCS_BONUS = \

OBJS = $(SRCS:.c=.o)
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

#ifdef WITH_BONUS
#	OBJECTS = $(OBJS) $(OBJS_BONUS)
#else
#	OBJECTS = $(OBJS)
#endif

$(NAME) : $(OBJS)
	@make -C ./libft all
	$(CC) $(CFLAGS) -o $@ $^ -L ./libft -lft

all : $(NAME)

#bonus : $(NAME_BONUS)
#	@make WITH_BONUS = 1

clean :
	@make -C ./libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	@make -C ./libft fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

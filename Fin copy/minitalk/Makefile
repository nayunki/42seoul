# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 21:06:38 by naki              #+#    #+#              #
#    Updated: 2023/01/26 21:49:24 by naki             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_S = server
NAME_C = client

SRCS_S = server.c
SRCS_C = client.c
SRCS = minitalk_utils.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(NAME_S) $(NAME_C)

$(NAME_S) : $(OBJS_S)
	cc -o $(NAME_S) $(OBJS_S) $(SRCS)

$(NAME_C) : $(OBJS_C)
	cc -o $(NAME_C) $(OBJS_C) $(SRCS)

all : $(NAME)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME_S)
	$(RM) $(NAME_C)

re :
	make fclean
	make all

.PHONY : all clean fclean re

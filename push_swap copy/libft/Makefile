# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 06:16:56 by naki              #+#    #+#              #
#    Updated: 2023/02/25 16:24:14 by naki             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rcs

NAME = libft.a

SRCS = \
	ft_isdigit.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_strncmp.c \
	ft_atoll.c \
	ft_calloc.c \
	ft_strjoin.c \
	ft_split.c \
	ft_lstnew.c \
	ft_lstclear.c \
	ft_memcpy.c \
	ft_strchr.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

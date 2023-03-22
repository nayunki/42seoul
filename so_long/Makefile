# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:03:50 by naki              #+#    #+#              #
#    Updated: 2023/02/12 08:18:16 by naki             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = \
	so_long.c \
	map_utils.c \
	hook_utils.c \
	valid_utils.c \
	image_utils.c \
	so_long_utils.c \
	get_next_line.c \
	get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wextra -Werror -Wall

CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

%.o :%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

NAME = philo

SRCS = \
	main.c \
	init.c \
	philo.c \
	philo_utils.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wextra -Werror -Wall -g

%.o :%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

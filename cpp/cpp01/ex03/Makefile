CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = War

SRCS = \
	main.cpp \
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
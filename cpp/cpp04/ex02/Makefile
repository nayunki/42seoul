CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = Abstract

SRCS = \
	main.cpp \
	AAnimal.cpp \
	Cat.cpp \
	Dog.cpp \
	Brain.cpp \

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
NAME = phonebook
SRCS = main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

OBJS = $(SRCS:.cpp=.o)
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

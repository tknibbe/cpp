NAME = zombie

SRC =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Wextra -Werror #-std=c++98

$(OBJ): $(SRC)
	$(compile) -c $(SRC)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

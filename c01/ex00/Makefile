NAME= Zombie

SRCS= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ= $(SRCS:.cpp=.o)

compile = c++ -Wall -Wextra -Werror -std=c++11

all: $(NAME)

%.o: %.cpp
	$(compile) -c $^

$(NAME): $(OBJ)
	$(compile) $(OBJ) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
NAME= executable

SRC= main.cpp

OBJ= $(SRC:.cpp=.o)

COMPILE= c++ -Wall -Wextra -Werror #-fsanitize=address -std=c++98

%.o : %.cpp
	$(COMPILE) -c $^

$(NAME): $(OBJ)
	$(COMPILE) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
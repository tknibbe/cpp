NAME= dream_job

SRC=	Account.cpp \
		tests.cpp

OBJ= $(SRC:.cpp=.o)

compile= c++ -Werror -Wall -Wextra -std=c++98

all: $(NAME)

$(OBJ): $(SRC)
	$(compile) -c $(SRC)

$(NAME): $(OBJ)
	$(compile) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
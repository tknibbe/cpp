NAME= dream_job

SRC=	Account.cpp \
		tests.cpp

OBJ= $(SRC:.cpp=.o)

compile= c++ -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(compile) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
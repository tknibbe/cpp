NAME= executable

SRC=  main.cpp Fixed.cpp

OBJ= ${SRC:.cpp=.o}

compile= c++ #-Wextra -Wall -Werror -std=c++11

all: $(NAME)

%.o: %.cpp
	$(compile) -c $^

${NAME}: ${OBJ}
	${compile} ${OBJ} -o ${NAME}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
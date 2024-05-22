NAME= executable

SRC=	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		wrongAnimal.cpp \
		wrongCat.cpp \
		Brain.cpp
		
OBJ= ${SRC:.cpp=.o}

compile= c++ -Wextra -Wall -Werror -std=c++11 #-fsanitize=address

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

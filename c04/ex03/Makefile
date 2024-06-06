NAME= executable

SRC=	main.cpp \
		AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp \
		Floor.cpp \
		MateriaSource.cpp
		

OBJ= ${SRC:.cpp=.o}

compile= c++ -Wextra -Wall -Werror -std=c++11 -fsanitize=address

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

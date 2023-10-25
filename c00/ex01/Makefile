NAME=phonebook

SRCS= main.cpp PhoneBook.cpp Contact.cpp

OBJS= $(SRCS:.cpp=.o)

compile = c++ -Wall -Wextra -Werror #-std=c++98

all: $(NAME)

$(OBJ): $(SRC)
	$(compile) -c $(SRC)

$(NAME): $(OBJS)
	$(compile) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
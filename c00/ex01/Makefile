NAME=phonebook

SRCS= Phonebook.cpp Contact.cpp

OBJS= $(SRCS:.cpp=.o)

compile = c++ -Wall -Wextra -Werror #-std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(compile) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
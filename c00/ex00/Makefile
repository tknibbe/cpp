NAME=megaphone

SRCS= megaphone.cpp

OBJS= $(SRCS:.cpp=.o)

compile = c++ -Wall -Wextra -Werror #-std=c++98

all: $(NAME)

%.o: %.cpp
	$(compile) -c $^

$(NAME): $(OBJS)
	$(compile) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
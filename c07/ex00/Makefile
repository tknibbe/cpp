NAME = executable

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES =	main.cpp \

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
DEP_FILES = $(OBJ_FILES:.o=.d)

CXX = c++ -std=c++11
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP_FILES)

clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d

fclean: clean
	rm -rf $(NAME)
	@rm -rf obj

re: fclean all

.PHONY: all clean fclean re


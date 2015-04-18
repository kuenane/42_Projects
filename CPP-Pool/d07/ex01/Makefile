NAME = iter

SRC_DIR = ./

SRC_FILES = iter.cpp

O_FILES = $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@clang++ -Wall -Werror -Wextra -o $(NAME) $^
	@echo "$(NAME) is ready :)"

%.o: $(SRC_DIR)%.cpp
	@clang++ -Wall -Wextra -Werror -o $@ -c $<

clean:
	@rm -f $(O_FILES) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

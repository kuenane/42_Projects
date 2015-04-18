NAME = phonebook

SRC_DIR = ./

H_DIR = ./

SRC_FILES = PhBook.class.cpp main.cpp

O_FILES = $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@clang++ -Wall -Werror -Wextra -I$(H_DIR) -o $(NAME) $^
	@echo "$(NAME) is ready :)"

%.o: $(SRC_DIR)%.cpp
	@clang++ -Wall -Wextra -Werror -o $@ -c $<

clean:
	@rm -f $(O_FILES) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

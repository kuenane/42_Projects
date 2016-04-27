NAME = Colleen

SRC_FILES = Colleen.c

O_FILES = $(SRC_FILES:.c=.o)

CC = clang

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILES)
	@$(CC) $(FLAGS) -o $(NAME) $^
	@echo "$(NAME) is ready :)"

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

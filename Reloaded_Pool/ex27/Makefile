NAME = ft_display_file

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = ft_display_file.c

O_FILES = $(SRC_FILES:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(CC_FLAGS) -O2 -o $(NAME) $^ -I$(INC_DIR)

%.o: $(SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -I$(INC_DIR) -o $@ -c $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

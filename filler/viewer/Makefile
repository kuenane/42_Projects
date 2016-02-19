NAME = viewer

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = main.c map.c draw.c

O_FILES = $(SRC_FILES:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra

# I_SDL2 = -I/usr/local/include/SDL2 -D_THREAD_SAFE
I_SDL2 = `sdl2-config --cflags`

# SDL2 = -L/usr/local/lib $(I_SDL2) -lSDL2
SDL2 = `sdl2-config --cflags --libs`

I_LIBFT = -I../libft/includes

LIBFT = -L../libft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C ../libft
	@$(CC) -Wall -Werror -Wextra -O2 -o $(NAME) $^ -I$(INC_DIR) $(LIBFT) $(SDL2)
	@echo "$(NAME) is ready :)"

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) $(I_LIBFT) $(I_SDL2) -o $@ -c $<
	@echo ".\c"

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

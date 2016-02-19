NAME = filler

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = main.c read.c utils.c algo.c algo_rand.c algo_spider.c algo_brute.c

SRC_BASE = $(SRC_DIR)main.c $(SRC_DIR)read.c $(SRC_DIR)utils.c
SRC_NORMAL = $(SRC_BASE) $(SRC_DIR)algo.c
SRC_RAND = $(SRC_BASE) $(SRC_DIR)algo_rand.c
SRC_SPIDER = $(SRC_BASE) $(SRC_DIR)algo_spider.c
SRC_BRUTE = $(SRC_BASE) $(SRC_DIR)algo_brute.c

O_FILES = $(SRC_FILES:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra

I_LIBFT = -Ilibft/includes

LIBFT = -Llibft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@echo ""

	@$(CC) $(CC_FLAGS) -O2 -o $(NAME) $(SRC_NORMAL) -I$(INC_DIR) $(LIBFT)
	@echo "$(NAME) is ready to fight :)"

	@$(CC) $(CC_FLAGS) -O2 -o rand $(SRC_RAND) -I$(INC_DIR) $(LIBFT)
	@echo "rand is ready to fight :)"

	@$(CC) $(CC_FLAGS) -O2 -o spider $(SRC_SPIDER) -I$(INC_DIR) $(LIBFT)
	@echo "spider is ready to fight :)"

	@$(CC) $(CC_FLAGS) -O2 -o brute $(SRC_BRUTE) -I$(INC_DIR) $(LIBFT)
	@echo "brute is ready to fight :)"

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)
	@echo ".\c"

clean:
	@make clean -C libft
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME) rand spider brute

re: fclean all

viewer:
	@make -C viewer

.PHONY: all clean fclean re viewer

NAME = lem-in

H_DIR = libft/includes

C_DIR = ./

C_FILES = main.c init_env.c put_room_tube_ant.c ft_t_room.c put_lit_path.c\
send_ants.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@clang -Wall -Werror -Wextra -O2 -o $(NAME) $^ -Ilibft/includes -Llibft -lft
	@echo "lem-in is ready :)"

%.o: $(C_DIR)%.c
	@clang -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $<
	@echo ".\c"

clean:
	@make clean -C libft
	@rm -f $(O_FILES) 

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

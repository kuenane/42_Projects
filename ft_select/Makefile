NAME = ft_select

H_DIR = libft/includes

C_DIR = ./

C_FILES = main.c init_env.c ft_list.c signal.c op_on_term.c print.c\
 manage_keys.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@clang -Wall -Werror -Wextra -O2 -o $(NAME) $^ -Ilibft/includes -Llibft -lft -ltermcap
	@echo "ft_select is ready :)"

%.o: $(C_DIR)%.c
	@clang -g -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $<
	@echo ".\c"

clean:
	@make clean -C libft
	@rm -f $(O_FILES) 

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = ft_minishell1

H_DIR = libft/includes

C_DIR = ./

C_FILES = bdin_cd.c bdin_chdir.c bdin_echo.c bdin_env.c bdin_exit.c\
 bdin_pwd.c bdin_setenv.c bdin_unsetenv.c check_rights.c check_the_cmd.c\
 check_the_path.c detected.c envp.c init_sh.c main.c print.c print2.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $^ -Ilibft/includes -Llibft -lft
	@echo "Makefile ft_minishell1 is ready :)"

%.o: $(C_DIR)%.c
	@gcc -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $<
	@echo ".\c"

clean:
	@make clean -C libft
	@rm -f $(O_FILES) 

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

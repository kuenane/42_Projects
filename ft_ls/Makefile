NAME = ft_ls

H_DIR = libft/includes

C_DIR = ./

C_FILES = a_option.c apply_options.c av_to_list.c enabled.c ft_ls.c\
 give_max.c give_max_files.c give_options_tab.c give_time_usr_gp.c\
 major_minor.c op_on_elem.c others.c print.c putstr_l_option.c\
 put_contents.c put_l_stat.c put_lopt.c rights.c sort.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $^ -Ilibft/includes -Llibft -lft
	@echo "Makefile ft_ls is ready :)"

%.o: $(C_DIR)%.c
	@gcc -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $<
	@echo ".\c"

clean:
	@make clean -C libft
	@rm -f $(O_FILES) 

fclean: clean
	@make fclean -C libft
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re

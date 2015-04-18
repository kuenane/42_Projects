NAME = push_swap

H_DIR = libft/includes

C_DIR = ./

C_FILES = action_pa_pb.c action_ra_rb_rr.c action_rra_rrb_rrr.c\
 action_sa_sb_ss.c algo_bruteforce.c algo_smartsort.c algo_various.c\
print_algo_smartsort.c check_if_solved.c convert_stack.c\
 interactive_mode.c main.c normal_mode.c op_on_stack.c\
 op_on_stack2.c put_struct_ps.c put_struct_ps2.c verbose.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $^ -Ilibft/includes -Llibft -lft
	@echo "Makefile push_swap is ready :)"

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

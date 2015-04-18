NAME = fdf

H_DIR = libft/includes

C_DIR = ./

C_FILES = check_errno_av_ac.c fdf.c ft_draw_pixel.c  ft_draw_line.c ft_getnbr.c\
 give_struct_mlx.c give_tab_map.c hook_move_map.c iso_projection.c nb_line.c pos_digit.c\
 put_map.c set_expose_and_key.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $^ -Ilibft/includes -Llibft -L/usr/X11/lib -lft -lmlx -lXext -lX11
	@echo "Makefile fdf is ready :)"

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

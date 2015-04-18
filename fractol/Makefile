NAME = fractol

H_DIR = libft/includes

C_DIR = ./

C_FILES = check_av_ac.c choose_color.c choose_color2.c chromosom.c douady_rabbit.c\
 fractol.c ft_draw_pixel.c give_struct_mlx.c julia.c mandelbrot.c mouse_hook.c\
 noun.c set_expose_and_key.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $^ -Ilibft/includes -Llibft -L/usr/X11/lib -lft -lmlx -lXext -lX11
	@echo "Makefile fractol is ready :)"

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

NAME = wolf3d

MLX =  -Lminilibx_macos -Iminilibx_macos -lmlx -framework OpenGL -framework AppKit

H_DIR = libft/includes

C_DIR = ./

C_FILES = main.c init_w3d.c set_expose_and_key.c ft_draw.c sky_and_floor_init.c\
sky_and_floor_put.c sky_and_floor_mv.c player_pos.c weapon.c move_hook.c\
put_wall.c put_wall2.c set_expose_and_key2.c minimap.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@make -C minilibx_macos
	@clang -Wall -Werror -Wextra -O2 -o $(NAME) $^ -Ilibft/includes -Llibft -lft $(MLX) -lm
	@echo "wolf3d is ready :)"

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

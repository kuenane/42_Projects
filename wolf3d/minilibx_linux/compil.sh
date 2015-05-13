#!/bin/bash
make -j -C libft ; make clean -C libft ; clang -Wall -Werror -Wextra -O2 -o wolf3d *.c -Ilibft/includes -Llibft -lft -Lminilibx_linux -Iminilibx_macos -lmlx -L/usr/X11/lib -lXext -lX11 -lm
NAME = app.exe

C_FILES = main.c menu.c wave.c args.c

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@gcc -o $(NAME) $^

%.o: %.c
	@gcc -I. -o $@ -c $<

clean:
	@rm -f $(O_FILES) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

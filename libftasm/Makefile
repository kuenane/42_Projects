NAME = libfts.a

S_DIR = ./

S_FILES = ft_bzero.s ft_cat.s ft_isalnum.s ft_isalpha.s ft_isascii.s\
 ft_isdigit.s ft_isprint.s ft_memalloc.s ft_memcpy.s ft_memset.s\
 ft_putchar.s ft_putnchar.s ft_putchar_fd.s ft_puts.s ft_puts_fd.s\
 ft_putstr.s ft_putstr_fd.s ft_strcat.s ft_strdup.s ft_strlen.s\
 ft_strnew.s ft_tolower.s ft_toupper.s

O_FILES = $(S_FILES:.s=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rcs $@ $^
	@ranlib $@
	@echo "\nLibft ASM is ready :)"

%.o: $(S_DIR)%.s
	@nasm -f macho64 --prefix _ -o $@ $<
	@echo ".\c"

clean:
	@rm -f $(O_FILES) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

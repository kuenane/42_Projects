NAME = libftprintf.a

HEADER_LOC = ./

SRC_LOC = ./

LIB_LOC = libft

SRC =	current_option_len.c current_option_put_tab.c\
 current_option_put_tab2.c ft_printf.c option_4242.c option_b.c\
 option_c.c option_d.c option_o.c option_p.c option_percent.c option_s.c\
 option_u.c option_x.c preci_min.c print_current_option.c width_min.c

OBJS = $(SRC:.c=.o)

LIB_OBJS = $(addprefix $(LIB_LOC)/,$(shell ls -1 $(LIB_LOC) | grep "\.o"))

all:
	@make -C $(LIB_LOC)
	@make $(NAME)

lib:
		@make -C $(LIB_LOC)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS) $(LIB_OBJS)
		@ranlib $(NAME)
		@echo "Lib libftprintf.a is ready :)"

%.o: $(SRC_LOC)/%.c
		@gcc -o $@ -I $(HEADER_LOC) -Ilibft/includes -c $^

clean: 
		@make -C $(LIB_LOC) clean
		@rm -rf $(OBJS)

fclean: clean
		@make -C $(LIB_LOC) fclean
		@rm -rf $(NAME)

re: fclean all

NAME = push_swap
SRC_DIR = SRC
SRCS =  $(addprefix $(SRC_DIR)/,\
	   main.c \
	   )

INCLUDE_DIR = includes

CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDE_DIR)

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	cc $(OBJS) Libft/libft.a ft_printf/ft_printf.a $(CFLAGS) -o $(NAME)

%.o: %.c
	cc $(OBJ_CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	make -C ft_printf clean
	rm -f $(OBJS)
	find . -type f -name "*.gch" -exec rm -f {} \;

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

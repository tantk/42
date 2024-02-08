NAME = ft_printf.a
SRCS = 	ft_utils.c \
		flag_csp.c \
		flag_diu.c \
		flag_xX.c \
		ft_printf.c \

INCLUDE_DIR = .

CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDE_DIR)
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C Libft
	ar rc $(NAME) Libft/libft.a $(OBJS)
	ar -s $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS)
	find . -type f -name "*.gch" -exec rm -f {} \;

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

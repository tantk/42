NAME = libft_test
SRCS = main.c \
	   ft_putchar_test.c
CLAGS = -g -Wall -Wextra -Werror
LIBRARY_DIR = ../Libft/
INCLUDE_DIR = /.
CC = cc
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBRARY_DIR) -lft
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

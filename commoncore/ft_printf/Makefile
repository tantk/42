NAME = libftprintf.a
LIBFT_DIR = Libft
LIBFT_SRCS =  $(addprefix $(LIBFT_DIR)/,\
		ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew_bonus.c \
	   ft_lstadd_front_bonus.c \
	   ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c \
	   ft_lstadd_back_bonus.c \
	   ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c \
	   ft_lstiter_bonus.c \
	   ft_lstmap_bonus.c \
	   )
PRINTF_DIR = Ft_printf
PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/,\
		ft_utils.c \
		flag_csp.c \
		flag_diu.c \
		flag_xX.c \
		ft_printf.c \
		)
INCLUDE_DIR = includes

CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDE_DIR)

LIBFT_OBJS = $(LIBFT_SRCS:%.c=%.o)

PRINTF_OBJS = $(PRINTF_SRCS:%.c=%.o)

ALL_OBJS = $(LIBFT_OBJS) $(PRINTF_OBJS)

all: $(NAME)

$(NAME): $(ALL_OBJS)
	ar rc $(NAME) $(ALL_OBJS)
	ar -s $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBFT_OBJS) $(PRINTF_OBJS)
	find . -type f -name "*.gch" -exec rm -f {} \;

fclean: clean
	rm -f $(NAME) $(LIBFT_NAME)

re: fclean all

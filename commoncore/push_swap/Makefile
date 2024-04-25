NAME = pushswap
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
	   )
PRINTF_DIR = ft_printf
PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/,\
		ft_utils.c \
		flag_csp.c \
		flag_diu.c \
		flag_xX.c \
		ft_printf.c \
		)
GNL_DIR = get_next_line
GNL_SRC = $(addprefix $(GNL_DIR)/,\
		  get_next_line.c \
		  get_next_line_utils.c \
		)
PS_DIR = src
PS_SRC = $(addprefix $(PS_DIR)/,\
main.c \
lst.c \
parser.c \
instructions.c \
error.c \
)

INCLUDE_DIR = includes

CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDE_DIR)

LIBFT_OBJS = $(LIBFT_SRCS:%.c=%.o)

PRINTF_OBJS = $(PRINTF_SRCS:%.c=%.o)

GNL_OBJS = $(GNL_SRC:%.c=%.o)

PS_OBJS = $(PS_SRC:%.c=%.o)

OBJS = $(LIBFT_OBJS) \
		   $(PRINTF_OBJS) \
		   $(GNL_OBJS) \
		   $(PS_OBJS) \

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	find . -type f -name "*.gch" -exec rm -f {} \;

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus

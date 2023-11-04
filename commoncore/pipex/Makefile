NAME = pipex
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
PIPEX_DIR = src
PIPEX_SRC = $(addprefix $(PIPEX_DIR)/,\
			main.c \
			findprog_utils.c \
			ft_errors.c \
			lst_func.c \
			parser.c \
			proc_utils.c \
			process.c \
			)

PIPEX_SRC_BONUS = $(addprefix $(PIPEX_DIR)/,\
			main_bonus.c \
			findprog_utils_bonus.c \
			ft_errors_bonus.c \
			lst_func_bonus.c \
			parser_bonus.c \
			proc_utils_bonus.c \
			process_bonus.c \
			)

INCLUDE_DIR = includes

CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDE_DIR)

LIBFT_OBJS = $(LIBFT_SRCS:%.c=%.o)

PRINTF_OBJS = $(PRINTF_SRCS:%.c=%.o)

GNL_OBJS = $(GNL_SRC:%.c=%.o)

PIPEX_OBJS = $(PIPEX_SRC:%.c=%.o)

PIPEX_BONUS_OBJS = $(PIPEX_SRC_BONUS:%.c=%.o)

MAN_OBJS = $(LIBFT_OBJS) \
		   $(PRINTF_OBJS) \
		   $(GNL_OBJS) \
		   $(PIPEX_OBJS) \

BONUS_OBJS = $(LIBFT_OBJS) \
			 $(PRINTF_OBJS) \
			 $(GNL_OBJS) \
			 $(PIPEX_BONUS_OBJS) \

all: $(NAME)

$(NAME): $(MAN_OBJS)
	cc $(CFLAGS) -o $(NAME) $(MAN_OBJS)

bonus: $(BONUS_OBJS)
	cc $(CFLAGS) -o $(NAME) $(BONUS_OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MAN_OBJS) $(BONUS_OBJS)
	find . -type f -name "*.gch" -exec rm -f {} \;

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus

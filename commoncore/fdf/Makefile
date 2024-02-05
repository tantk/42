NAME = fdf
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

FDF_DIR = src
FDF_SRC = $(addprefix $(FDF_DIR)/,\
			main.c \
			parse_map.c \
			parse_map_utils.c \
			fdf_errors.c \
			parse_utils.c \
			lst_func.c \
			matrix.c \
			drawing.c \
			drawing_util.c \
			display.c \
			hooks.c \
		)

INCLUDE_DIR = includes

MLX_INCLUDE_DIR = mlx_linux

OBJ_CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I $(MLX_INCLUDE_DIR)

EX_CFLAGS =  -g -Wall -Wextra -Werror -I $(MLX_INCLUDE_DIR) -L $(MLX_INCLUDE_DIR) -l mlx  -lXext -lX11 -lm


LIBFT_OBJS = $(LIBFT_SRCS:%.c=%.o)

PRINTF_OBJS = $(PRINTF_SRCS:%.c=%.o)

GNL_OBJS = $(GNL_SRC:%.c=%.o)

FDF_OBJS = $(FDF_SRC:%.c=%.o)

ALL_OBJS = $(LIBFT_OBJS) \
		   $(PRINTF_OBJS) \
		   $(GNL_OBJS) \
		   $(FDF_OBJS) \

all: $(NAME)

$(NAME): $(ALL_OBJS)
	cc $(ALL_OBJS) $(EX_CFLAGS) -o $(NAME)

%.o: %.c
	cc $(OBJ_CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS)
	find . -type f -name "*.gch" -exec rm -f {} \;

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

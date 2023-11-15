NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT_PATH = ./libft/*.o ./libft/*.a

SRCS = ft_printf_utils/ft_check_conversion.c \
	ft_printf_utils/ft_printf.c \
	ft_printf_utils/ft_put_hex.c \
	ft_printf_utils/ft_put_unsigned.c \
	ft_printf_utils/ft_put_void_pointer.c \
	ft_printf_utils/ft_putchar.c \
	ft_printf_utils/ft_putnbr_base.c \
	ft_printf_utils/ft_putnbr_hex.c \
	ft_printf_utils/ft_putnbr.c \
	ft_printf_utils/ft_putstr.c

BONUS_SRCS = \
	ft_printf_utils_bonus/ft_printf_bonus.c \
	ft_printf_utils_bonus/ft_put_unsigned_bonus.c \
	ft_printf_utils_bonus/ft_put_voidpointer_bonus.c \
	ft_printf_utils_bonus/ft_putchar_bonus.c \
	ft_printf_utils_bonus/ft_putnbr_base_bonus.c \
	ft_printf_utils_bonus/ft_putnbr_bonus.c \
	ft_printf_utils_bonus/ft_putstr_bonus.c \
	ft_printf_utils_bonus/ft_putnbr_hex_bonus.c \
	ft_printf_utils_bonus/ft_put_hex_bonus.c \
	ft_printf_utils_bonus/ft_check_conversion_bonus.c \
	ft_printf_utils_bonus/ft_putnbr_str_bonus.c

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
MAKEFLAG += make --no-print-directory

ifdef WITH_BONUS
	OBJ = $(BONUS_OBJ)
endif

all: libft $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(BONUS_OBJ) $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: $(if $(wildcard $(OBJ)), fclean)
	$(MAKEFLAG) WITH_BONUS=TRUE

libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus libft

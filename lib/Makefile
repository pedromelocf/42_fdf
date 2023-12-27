NAME = libftprintf.a

LIBFT_DIR = libft
LIB_PATH = ./libft/*.o ./libft/*.a

#GNL
GNL_SRC_PATH = ./gnl/
GNL_INCLUDES = ./gnl/get_next_line.h
GNL_OBJ = $(addprefix $(GNL_SRC_PATH), $(GNL_SRCS:.c=.o))

GNL_SRCS = get_next_line_utils.c \
	get_next_line.c

#PRINTF
PRINTF_SRC_PATH = ./printf/
PRINTF_INCLUDES = ./printf/ft_printf.h
PRINTF_OBJ = $(addprefix $(PRINTF_SRC_PATH), $(PRINTF_SRCS:.c=.o))

PRINTF_SRCS = ft_check_conversion.c \
	ft_printf.c \
	ft_putchar.c \
	ft_put_hex.c \
	ft_putnbr_base.c \
	ft_putnbr.c \
	ft_putnbr_hex.c \
	ft_putstr.c \
	ft_put_unsigned.c \
	ft_put_void_pointer.c

FLAGS = -Wall -Werror -Wextra
CC = cc
MAKEFLAG += make --no-print-directory

all: libft $(NAME)

$(NAME): $(GNL_OBJ) $(PRINTF_OBJ)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(GNL_OBJ) $(PRINTF_OBJ)

$(GNL_SRC_PATH)%.o: $(GNL_SRC_PATH)%.c $(GNL_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

$(PRINTF_SRC_PATH)%.o: $(PRINTF_SRC_PATH)%.c $(PRINTF_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(LIB_PATH) $(GNL_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft

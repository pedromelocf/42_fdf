#LIBFT
LIB_SRC_PATH = ./libft/
LIB_INCLUDES = ./libft.h
LIB_OBJ = $(addprefix $(LIB_SRC_PATH), $(LIB_SRCS:.c=.o))

LIB_SRCS = ft_isalpha.c \
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
	ft_putnbr_fd.c

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

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME)

$(NAME): $(LIB_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	ar rcs $(NAME) $(LIB_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

$(LIB_SRC_PATH)%.o: $(LIB_SRC_PATH)%.c $(LIB_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

$(GNL_SRC_PATH)%.o: $(GNL_SRC_PATH)%.c $(GNL_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

$(PRINTF_SRC_PATH)%.o: $(PRINTF_SRC_PATH)%.c $(PRINTF_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(LIB_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

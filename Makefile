NAME = fdf

LIBFT_DIR = ./lib
LIBFT_PATH = ./lib/libft/*.o ./lib/*.a
GNL_PATH = ./lib/gnl/*.o
PRINTF_PATH = ./lib/printf/*.o

# BONUS_SRCS = \

FDF_SRC_PATH = ./fdf_utils/
INCLUDES = ./fdf_utils/includes/fdf.h
LIB_OBJ = $(addprefix $(FDF_SRC_PATH), $(FDF_SRCS:.c=.o))

FDF_SRCS = main.c

# BONUS_OBJ = $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
MAKEFLAG += make --no-print-directory

ifdef WITH_BONUS
	OBJ = $(BONUS_OBJ)
endif

all: libft $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(FDF_SRC_PATH)%.o: $(FDF_SRC_PATH)%.c $(FDF_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(BONUS_OBJ) $(LIBFT_PATH) $(GNL_PATH) $(PRINTF_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: $(if $(wildcard $(OBJ)), fclean)
	$(MAKEFLAG) WITH_BONUS=TRUE

libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus libft

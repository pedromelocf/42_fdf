#LIBFT
LIBFT_DIR = ./lib
LIBFT_OBJ = ./lib/libft/*.o ./lib/*.a
GNL_OBJ = ./lib/gnl/*.o
PRINTF_OBJ = ./lib/printf/*.o

#FDF
FDF_SRC_PATH = ./fdf_utils/
FDF_INCLUDES = ./fdf_utils/includes/fdf.h
FDF_OBJ = $(addprefix $(FDF_SRC_PATH), $(FDF_SRCS:.c=.o))

FDF_SRCS = main.c

FDF_BONUS_SRCS = \

FDF_BONUS_OBJ = $(FDF_BONUS_SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
MAKEFLAG += make --no-print-directory

ifdef WITH_BONUS
	FDF_OBJ = $(BONUS_OBJ)
endif

NAME = fdf

all: libft $(NAME)

$(NAME): $(FDF_OBJ)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(FDF_OBJ)

$(FDF_SRC_PATH)%.o: $(FDF_SRC_PATH)%.c $(FDF_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(FDF_OBJ) $(BONUS_OBJ) $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: $(if $(wildcard $(OBJ)), fclean)
	$(MAKEFLAG) WITH_BONUS=TRUE

libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus libft

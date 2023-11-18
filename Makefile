#LIBFT
LIBFT_DIR = ./lib
LIBFT_OBJ = ./lib/libft/*.o ./lib/*.a
GNL_OBJ = ./lib/gnl/*.o
PRINTF_OBJ = ./lib/printf/*.o

#FDF MANDATORY
FDF_SRC_PATH = ./fdf_utils/
FDF_INCLUDES = ./fdf_utils/includes/fdf.h
FDF_OBJ = $(addprefix $(FDF_SRC_PATH), $(FDF_SRCS:.c=.o))

FDF_SRCS = main.c

#FDF BONUS
FDF_BONUS_SRC_PATH =./fdf_utils_bonus/
FDF_BONUS_INCLUDES =./fdf_utils_bonus/includes/fdf_bonus.h
FDF_BONUS_OBJ = $(addprefix $(FDF_BONUS_SRC_PATH), $(FDF_BONUS_SRCS:.c=.o))

FDF_BONUS_SRCS = \

ifdef WITH_BONUS
	FDF_OBJ = $(FDF_BONUS_OBJ)
endif

NAME = fdf
FLAGS = -Wall -Werror -Wextra
MAKEFLAG += make --no-print-directory

all: libft $(NAME)

$(NAME): $(FDF_OBJ)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(FDF_OBJ)

$(FDF_SRC_PATH)%.o: $(FDF_SRC_PATH)%.c $(FDF_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(FDF_OBJ) $(FDF_BONUS_OBJ) $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: $(if $(wildcard $(OBJ)), fclean)
	$(MAKEFLAG) WITH_BONUS=TRUE

libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus libft

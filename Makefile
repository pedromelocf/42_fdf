#LIBFT
LIBFT_DIR = ./lib
LIBFT_PATH1 = ./lib/libft/*.o ./lib/libft/*.a
LIBFT_PATH2 = ./lib/*.a
GNL_OBJ = ./lib/gnl/*.o
PRINTF_OBJ = ./lib/printf/*.o

#FDF MANDATORY
FDF_SRC_PATH = ./fdf_utils/
FDF_INCLUDES = ./fdf_utils/includes/fdf.h
FDF_OBJ = $(addprefix $(FDF_SRC_PATH), $(FDF_SRCS:.c=.o))

FDF_SRCS = main.c \
	check_map_format.c \
	map_read.c \
	draw_pixels.c \
	clean_data.c \
	key_hook.c \
	convert_matrix.c \
	draw_line.c \
	get_matrix_dimensions.c \
	task_mlx.c \
	utils.c


#MLX42
LIB_MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm
# LIBMLX_SRC_PATH = ./MLX/src/*.c
# LIBMLX_INCLUDES = ./MLX/include/*.h
# LIBMLX_OBJ = $(addprefix $(LIBMLX_SRC_PATH), $(LIBMLX_SRCS:.c=.o))
LIB_MLX_SRCS = MLX42/build/libmlx42.a


NAME = fdf
FLAGS = -Wall -Werror -Wextra
MAKEFLAG += make --no-print-directory

all: libft $(NAME)

$(NAME): $(FDF_OBJ)
	cp $(LIBFT_DIR)/libftprintf.a $(NAME)
	ar rcs $(NAME) $(FDF_OBJ)
	$(CC) $(NAME) $(LIB_MLX_SRCS) $(LIB_MLX_FLAGS)

$(FDF_SRC_PATH)%.o: $(FDF_SRC_PATH)%.c $(FDF_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(FDF_OBJ) $(LIBFT_PATH1) $(LIBFT_PATH2) $(GNL_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft

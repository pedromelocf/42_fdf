#LIBFT
LIBFT_DIR = ./lib
LIBFT_PATH = ./lib/libft/*.o ./lib/libft/*.a
LIB_PATH = ./lib/*.a
GNL_OBJ = ./lib/gnl/*.o
PRINTF_OBJ = ./lib/printf/*.o

#FDF
NAME = fdf
FDF_SRC_PATH = ./fdf_utils/
FDF_INCLUDES = ./fdf_utils/includes/fdf.h
FDF_OBJ = $(addprefix $(FDF_SRC_PATH), $(FDF_SRCS:.c=.o))

FDF_SRCS = check_map_format.c \
	clean_data.c \
	convert_matrix.c \
	draw_line.c \
	get_matrix_dimensions.c \
	key_hook.c \
	main.c \
	map_read.c \
	print_return.c \
	render.c \
	task_mlx.c \
	utils.c

#MLX42
LIB_MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm
LIB_MLX_SRCS = MLX42/build/libmlx42.a

#HEADERS
LIB_HEADERS = -I libs/Libft/ -I libs/MLX42/include/

#FLAGS
FLAGS = -Wall -Werror -Wextra
CC = cc
MAKEFLAG += make --no-print-directory

all: libft $(NAME)

$(NAME): $(FDF_OBJ)
	$(CC) $(FLAGS) $(FDF_OBJ) $(LIB_PATH) $(LIB_MLX_SRCS) $(LIB_MLX_FLAGS) $(LIB_HEADERS) -o $(NAME)

$(FDF_SRC_PATH)%.o: $(FDF_SRC_PATH)%.c $(FDF_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(FDF_OBJ) $(LIBFT_PATH) $(LIB_PATH) $(GNL_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

libft :
	$(MAKEFLAG) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libftprintf.a $(NAME)

.PHONY: all clean fclean re libft

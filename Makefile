NAME = fdf

LIBFT_DIR = ./lib
LIBFT_PATH = ./lib/*.o ./lib/*.a

SRCS =

BONUS_SRCS = \


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

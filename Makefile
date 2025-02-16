NAME = fractol
CC = cc
AR = ar rcs
FLAGS = -L./libft -L./ft_printf -lft -lftprintf
INCLUDES = -I./headers/ -I./libft/headers/ -I./ft_printf/headers/
LIBFT = libft.a
FT_PRINTF = libftprintf.a

SRC =	main.c \
		julia.c \
		extra.c \
		mandelbrot.c \
		burningship.c \
		events.c \
		key_hooks.c \
		color.c \
		draw.c \
		complex.c \
		parser.c 

SRC_DIR = src
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	$(CC) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME) -lmlx -lXext -lX11 -lm -lz $(INCLUDES) -Ofast


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(INCLUDES) -o $@

$(LIBFT):
	make -C libft/ re
	cp libft/$(LIBFT) ./

$(FT_PRINTF):
	make -C ft_printf/ re
	cp ft_printf/$(FT_PRINTF) ./

clean:
	make -C libft/ fclean
	make -C ft_printf/ fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(FT_PRINTF)

re: fclean all

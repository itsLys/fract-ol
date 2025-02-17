GREEN  =	\033[0;32m
YELLOW =	\033[0;33m
RED    =	\033[0;31m
RESET  =	\033[0m

NAME =		fractol
CC =		cc
AR =		ar rcs
INCLUDES =	-I./headers/ -I./libft/headers/
LIBFT =		libft.a

SRC =		main.c \
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

SRC_DIR =	src
OBJ_DIR =	obj
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME) -lmlx -lXext -lX11 -lm -lz $(INCLUDES) -Ofast
	@echo "$(GREEN)$(BOLD)$(NAME) done!$(RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "	$(YELLOW) compiling $<$(RESET)"
	@$(CC) -c $< $(INCLUDES) -o $@

$(LIBFT):
	@make -C libft/ re
	@cp libft/$(LIBFT) ./

clean:
	@echo "$(RED)$(BOLD)Cleaning $(OBJ_DIR)...$(RESET)"
	@make -C libft/ fclean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)$(BOLD)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME) $(LIBFT)

re: fclean all

GREEN  =	\033[0;32m
YELLOW =	\033[0;33m
RED    =	\033[0;31m
RESET  =	\033[0m

NAME =		fractol
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -Ofast
LFLAGS =	-lmlx -lXext -lX11 -lm
AR =		ar rcs
INCLUDES =	-I./headers/ -I./libft/headers/
LIBFT =		libft.a

SRC =		main.c \
			julia.c \
			extra.c \
			mandelbrot.c \
			burningship.c \
			events.c \
			color.c \
			color_utils.c \
			draw.c \
			parser.c \
			navigation_hooks.c \
			options_hooks.c
SRC_DIR =	src
OBJ_DIR =	obj
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(LFLAGS) $(INCLUDES)
	@echo "$(GREEN)$(BOLD)$(NAME) done!$(RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)compiling $<$(RESET)"
	@$(CC) -c $< $(INCLUDES) $(CFLAGS) -o $@

$(LIBFT):
	@make -C libft/ all
	@cp -p libft/$(LIBFT) $(LIBFT)

clean:
	@make -C libft/ clean
	@echo "$(RED)$(BOLD)Cleaning $(OBJ_DIR)...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft/ fclean
	@echo "$(RED)$(BOLD)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re

.SECONDARY: $(OBJ) $(LIBFT)

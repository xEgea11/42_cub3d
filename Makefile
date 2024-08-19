NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
INCLUDE_MLX = MLX42/include/MLX42/
LIBFT_DIR = libft/
LIBFT = libft/libft.a
MLX_DIR = MLX42/build/
LIBMLX = $(MLX_DIR)libmlx42.a

#colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

#For MacOS
FLAGSMLX_MAC = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
FLAGSMLX_LINUX =  

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)					# Check the name of your OS
	FLAGSMLX = $(FLAGSMLX_LINUX)
else
	FLAGSMLX = $(FLAGSMLX_MAC)
endif

SRC_FILES = main.c \
			player.c \
			init_game.c \
			drawings.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


$(NAME): $(OBJ)
	@echo "$(GREEN)OS is... $(UNAME_S)$(RESET)"
	@echo "$(YELLOW)Lin-king...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	$(CC)  -o $(NAME) $(OBJ) $(LIBFT)  $(LIBMLX) $(FLAGSMLX) 
	@echo "$(GREEN)Build successful!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(INCLUDE_MLX) -c $< -o $@

.PHONY: all clean fclean re run

all: $(NAME)

run:
	./$(NAME) 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

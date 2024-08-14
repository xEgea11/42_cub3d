NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
INCLUDE_MLX = MLX42/include/MLX42/
MLX_DIR = MLX42/build/
LIBMLX = $(MLX_DIR)libmlx42.a

#For MacOS
FLAGSMLX = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
#FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC_FILES = main.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

$(NAME): $(OBJ)
	@echo "$(YELLOW)Linking...$(RESET)"
	$(CC)  -o $(NAME) $(OBJ) $(LIBMLX) $(FLAGSMLX)
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

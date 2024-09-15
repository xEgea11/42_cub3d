NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
INCLUDE_MLX = MLX42/include/MLX42/
PARSE_DIR = parsing/
LIBFT_DIR = libft/
LIBFT = libft/libft.a
MLX_DIR = MLX42/build/
LIBMLX = $(MLX_DIR)libmlx42.a

#file´s directories
PARSE_DIR = parsing
MATH_GRAPHICS_DIR = math_graphics

#colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

#For MacOS
FLAGSMLX_MAC = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
FLAGSMLX_LINUX = -ldl -lglfw -lGL -lX11 -lpthread -lm

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)					# Check the name of your OS
	FLAGSMLX = $(FLAGSMLX_LINUX)
else
	FLAGSMLX = $(FLAGSMLX_MAC)
endif

GAME_FILES = main.c \
			player.c \
			player_movement.c \
			movement_utils.c \
			init_game.c \
			raycast.c \
			map_drawings.c \
			minimap_draw_utils.c \
			3d_projection.c \
			3d_projection_utils.c \
			ray_utils.c \


PARSING_FILES = parsing.c \
				parsing_map.c \
				parsing_map_ext.c \
				parsing_textures.c \
				parsing_textures2.c \
				parsing_player.c \
				free_data.c \
				map_data.c \
				aprove_map.c \
				aprove_map_ext.c \
				aprove_map2.c \
				aprove_map_is_close.c \
				init_textures.c \

SRC_FILES = $(addprefix $(MATH_GRAPHICS_DIR)/, $(GAME_FILES))
SRC_FILES += $(addprefix $(PARSE_DIR)/, $(PARSING_FILES))
			

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	@echo "$(GREEN)OS is... $(UNAME_S)$(RESET)"
	@echo "$(YELLOW)Lin-king...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	$(CC)  -o $(NAME) $(OBJ) $(LIBFT)  $(LIBMLX) $(FLAGSMLX) 
	@echo "$(GREEN)Build successful!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/*.h			# Remove later, wildcards not allowed
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(INCLUDE_MLX) -c $< -o $@

.PHONY: all clean fclean re run

all: $(NAME)

run:
	./$(NAME) maps/map01.cub

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
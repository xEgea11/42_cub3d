NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "$(GREEN)Build successful!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

.PHONY: all clean fclean re run

all: $(NAME)

run:
	./$(NAME) 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

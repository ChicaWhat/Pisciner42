# Makefile

# ================== VARIABLES ==================

# Name of the project
NAME = fractol

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
#-fsanitize=address -g

# Directories
LIBFT_DIR = ./libft
MLX_DIR = ./MLX42
SRC_DIR = src
OBJ_DIR = obj

# Libraries
# Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

# MLX42
# IMPORTANT: Assuming the static library is generated in build/
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
# MLX headers so the compiler can find them
MLX_INC = -I $(MLX_DIR)/include
# MANDATORY flags to link MLX42
# -ldl: Dynamic Loader
# -lglfw: Base graphics library
# -pthread: Multithreading
# -lm: Math library
MLX_FLAGS = -ldl -lglfw -pthread -lm

# Source files
SRC_FILES = main.c \
            error.c \
            init.c \
            mandelbrot.c \
            colors.c \
            julia.c \
            utils.c \
            maths.c \

# Full paths to source files
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Objects
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# ================== RULES ==================

all: $(NAME)

# Main rule
# Depends on Libft, MLX, and my objects existing
$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

# Compiling objects (.c -> .o)
# ADDED $(MLX_INC): Necessary to find "MLX42/MLX42.h"
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@
	@echo "$(GREEN)🔨 Compiling: $<$(RESET)"

# Rule to compile Libft if it doesn't exist
$(LIBFT):
	@echo "$(GREEN)📦 Building Libft...$(RESET)"
	@$(LIBFT_MAKE)

# Rule to compile MLX42 if it doesn't exist
# MLX42 uses CMAKE, not standard Make.
$(MLX_LIB):
	@echo "$(GREEN)📦 Building MLX42...$(RESET)"
	@cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	@cmake --build $(MLX_DIR)/build -j

clean:
	@rm -rf $(OBJ_DIR)
	@$(LIBFT_MAKE) clean
	@echo "$(RED)🧹 Object files cleaned!$(RESET)"

fclean: clean
	@rm -rf $(MLX_DIR)/build
	@rm -f $(NAME)
	@$(LIBFT_MAKE) fclean
	@echo "$(RED)🗑️  $(NAME) and libraries cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
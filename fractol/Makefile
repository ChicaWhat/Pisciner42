# Makefile

# ================== VARIABLES ==================

# Name of the project
NAME = fractol

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

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
# IMPORTANTE: Asumo que la librería estática se genera en build/
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
# Headers de MLX para que el compilador los encuentre
MLX_INC = -I $(MLX_DIR)/include
# Flags OBLIGATORIAS para linkar MLX42 en Linux/42 School
# -ldl: Dynamic Loader
# -lglfw: La librería gráfica base
# -pthread: Multihilo
# -lm: Librería matemática (Math)
MLX_FLAGS = -ldl -lglfw -pthread -lm

# Source files (Solo pongo main.c porque es lo que tienes ahora)
SRC_FILES = main.c \
			error.c \

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

# Regla principal
# Depende de que existan la Libft, la MLX y tus objetos
$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

# Compilación de objetos (.c -> .o)
# AÑADIDO $(MLX_INC): Necesario para que encuentre "MLX42/MLX42.h"
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@
	@echo "$(GREEN)🔨 Compiling: $<$(RESET)"

# Regla para compilar la Libft si no existe
$(LIBFT):
	@echo "$(GREEN)📦 Building Libft...$(RESET)"
	@$(LIBFT_MAKE)

# Regla para compilar la MLX42 si no existe
# MLX42 usa CMAKE, no Make standard. Esta es la forma correcta de compilarla.
# Regla para compilar la MLX42
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
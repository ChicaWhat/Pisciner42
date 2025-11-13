# Makefile

# ================== VARIABLES ==================

# Name of the proyect
NAME = push-swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./libft
SRC_DIR = src
OBJ_DIR = obj
# INC_DIR = inc

# Sources files
SRC_FILES = main.c \
			error.c \
			nodes.c \
			move_rotate.c \
			move_reverse_rotate.c \
			move_swap.c \
			move_push.c \
			order_array.c \
			algorith.c \
			utils.c \

# Full paths to source files
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Libft variables
LIBFT = $(LIBFT_DIR)/libft.a
# LIBFT_INC = $(LIBFT_DIR)
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

# Objects
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Includes paths
# INCLUDES = -I$(INC_DIR) -I$(LIBFT_INC)

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# ================== RULES ==================

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🔨 Compiling: $<$(RESET)"

$(LIBFT):
	@$(LIBFT_MAKE)

clean:
	@rm -rf $(OBJ_DIR)
	@$(LIBFT_MAKE) clean
	@echo "$(RED)🧹 Object files cleaned!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(LIBFT_MAKE) fclean
	@echo "$(RED)🗑️  $(NAME) and library cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
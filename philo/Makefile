# Nombre del programa
NAME = philo

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

# Directorios
SRC_DIR = src
OBJ_DIR = obj

# Archivos fuente (Añade aquí los tuyos cuando los crees)
SRC_FILES = main.c \
			parser.c \
			utils.c \
			clean.c \
			init.c \
			

# Rutas completas a los archivos fuente
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Objetos
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colores
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# ================== REGLAS ==================

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🔨 Compiling: $<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)🧹 Object files cleaned!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  $(NAME) cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
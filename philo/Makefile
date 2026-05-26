NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=address

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.c \
			parser.c \
			utils.c \
			clean.c \
			init_struct.c \
			init_philos.c \
			print.c \
			routine.c \
			states.c \
			states2.c \
			threads.c \
			utils2.c \
			

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# ================== RULES ==================

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
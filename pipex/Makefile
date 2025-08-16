# Makefile

# ================== VARIABLES ==================

# Name of the proyect
NAME = pipex

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ../libft
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes # Para el .h del pipex

# Sources files
SRC_FILES = pipex.c \
            pipex_utils.c \

# Libft variables
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/includes
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

# Objects
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:%c=%.o))

# Includes paths
INCLUDES = -I(INC_DIR) -I(LIBFT_INC)

# Compilation command
COMPILE = $(CC) $(CFLAGS) $(INCLUDES)

# Colors
GREEN = \033[0;32m
RED        = \033[0;31m
RESET      = \033[0m

# ================== RULES ==================

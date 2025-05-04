# Makefile

# VARIABLES

# Name of the final library
NAME = libft.a

# Command to compile
CC = cc

CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_strlen.c \
      ft_memset.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strrchr.c \
	ft_memchr.c \
	ft_memcmp.c

# Name of my main
MAIN = example.c

# Name of my program
PROGRAM = ./a.out

# Object files
OBJ = $(SRC:%.c=%.o)
	
# Make libraries
AR = ar rcs

# Rule to compile all
all: $(NAME)

# Rule to compile my program
run: $(PROGRAM)
	$(PROGRAM)

$(PROGRAM): $(MAIN) $(NAME) 
	$(CC) $(CFLAGS) $(MAIN) ${NAME} -o $@

# Rule to create the library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Create .o files from .c 
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

# Removes every object inside the directory
clean:
	rm -rf $(OBJ)

# Removes the final files made with this makefile by force, executing clean as well
fclean: clean
	rm -f $(NAME)

pclean: fclean 
	rm -f $(PROGRAM)

# Restarts the Makefile. Erase everything and executes again
re: fclean all

.PHONY: all clean fclean re

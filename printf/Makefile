# Makefile

# Name of the ft_printf library
NAME = libftprintf.a

# Command to compile
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Sources files
SRC = 

# Main
MAIN = main.c

# Program
PROGRAM = ./a.exe

# Object files
OBJ = $(SRC:%.c=%.o)

# Make the library
AR = ar rcs

# Rule to compile all
all: $(NAME)

# Rule to run the program
run: $(PROGRAM)
	@echo "Ejecutando el programa..."
	@$(PROGRAM)
# Rule to compile the program
$(PROGRAM): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $@

# Rule to create the library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Rule to compile all the .c to o.
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -r $(OBJ)

flcean: clean
	rm -r $(NAME)

pclean: fclean
	rm -r $(PROGRAM)

# Restart the Makefile. Erase everything and executes again
re: fclean all

.PHONY: all clean fclean re run pclean


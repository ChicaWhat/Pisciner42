# Makefile

# Name of the ft_printf library
NAME = libftprintf.a

# Command to compile
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Sources files
SRC = ft_printf.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_nbr.c \
	ft_print_hex_top.c \
	ft_print_hex_bottom.c \
	ft_print_ptr.c \
	ft_print_uns.c

# Main
#MAIN = main.c

# Program
#PROGRAM = ./a.out

# Object files
OBJ = $(SRC:%.c=%.o)

# Make the library
AR = ar rcs

# Rule to compile all
all: $(NAME)

# Rule to run the program
#run: $(PROGRAM)
#	@echo "Ejecutando el programa..."
#	@$(PROGRAM)
# Rule to compile the program
#$(PROGRAM): $(MAIN)
#	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $@

# Rule to create the library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Rule to compile all the .c to o.
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

#pclean: fclean
#	rm -r $(PROGRAM)

# Restart the Makefile. Erase everything and executes again
re: fclean all

.PHONY: all clean fclean re


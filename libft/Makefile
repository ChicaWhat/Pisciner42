# Makefile

# VARIABLES

# Name of the final library
NAME = libft.a

# Command to compile
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = \
	ft_isalpha.c \
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
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

# Source bonus files
SRC_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c

# Object files
OBJ = $(SRC:%.c=%.o)

# Command to create the bonus
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
	
# Make libraries
AR = ar rcs

# Rule to compile all
all: $(NAME)

# Rule to compile all + the bonus
bonus: $(OBJ) $(OBJ_BONUS)
	@$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

# Rule to create the library
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

# Rule to create .o files from .c to the bonus functions
$(OBJ_BONUS): $(SRC_BONUS)
	@$(CC) $(CFLAGS) -c $^

# Create .o files from .c 
$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $^

# Removes every object inside the directory
clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

# Removes the final files made with this makefile by force, executing clean as well
fclean: clean
	rm -f $(NAME) $(BONUS)

# Restarts the Makefile. Erase everything and executes again
re: fclean all

# Restarts the Makefile. Erase everything + bonus and executes again
rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus

NAME = libftprintf.a

# compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror
DEBUG = -g

LIBFT = libft

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/

# files
# SRC_FILES = ft_printf.c
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)

# full path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INCLUDES = -I $(LIBFT_DIR)includes/ -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEBUG) $(INCLUDES) -c $^
	@mv -f *.o $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)

re: fclean all

test: re
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) $(NAME) main.c

f:
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) $(NAME) main.c

.PHONY: all clean fclean re $(NAME)

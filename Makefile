# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 20:11:50 by mtan              #+#    #+#              #
#    Updated: 2018/03/11 20:11:51 by mtan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mtan.filler

# compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror
DEBUG = -g

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/
LIBFT_DIR = ft_printf/libft/

# files
# SRC_FILES = ft_printf.c
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o) get_next_line.o
PRINTF = $(PRINTF_DIR)/libftprintf.a

# full path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES)) $(GNL_DIR)get_next_line.c
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INCLUDES =	-I $(PRINTF_DIR)includes/ -I $(LIBFT_DIR)includes \
			-I $(GNL_DIR) -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(PRINTF)
	@cp $(NAME) resources/players/
	@echo "[INFO] Player mtan created."

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) -c $^
	@mv -f *.o $(OBJ_DIR)

clean:
	@$(MAKE) -C ft_printf/ clean
	@rm -rf $(OBJ_DIR)
	@echo "[INFO] Objects removed."

fclean: clean
	@$(MAKE) -C ft_printf/ fclean
	@rm $(NAME)
	@rm resources/players/$(NAME)
	@echo "[INFO] Player mtan removed"

re: fclean all

.PHONY: all $(NAME) clean fclean re

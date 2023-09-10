# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 16:24:12 by dgerguri          #+#    #+#              #
#    Updated: 2023/05/09 17:12:14 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_D = ./libft

INCLUDE = -I ./includes/

SRC_DIR = ./srcs/

SRC = main.c input_validation.c error.c stack.c\
swap.c push.c rotate.c reverse.c sorting.c\
stack_utils.c push_swap.c sorting_utils_first.c sorting_utils_second.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME) project! $(RESET)"
	@$(MAKE) -C $(LIBFT_D)
	@$(CC) $(FLAGS) $(MLX) $(OBJ) -o $(NAME) -L $(LIBFT_D) -lft

clean:
	@$(MAKE) clean -C $(LIBFT_D)
	@$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "$(RED)Removed object files from $(NAME)!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_D)
	@$(RM) $(NAME)
	@echo "$(RED)Removed $(NAME)!$(RESET)"

re:fclean all

.PHONY: all clean fclean re

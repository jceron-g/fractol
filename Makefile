# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 10:34:28 by jceron-g          #+#    #+#              #
#    Updated: 2024/01/17 12:55:07 by jceron-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
USER = jceron-g
CC = gcc
CFLAGS = -Wextra -Wall -Werror 
MLX42 = lib/MLX42
LIBFT = lib/libft
SRC_DIR = src/
OBJ_DIR = obj/

DEF_COLOR = \033[0;39m
MAGENTA   = \033[35;1m
YELLOW    = \033[33;1m
GREEN     = \033[32;1m
WHITE     = \033[37;1m
RESET     = \033[0m
GRAY 	  = \033[0;90m
BLUE      = \033[34;1m
CYAN      = \033[37;1m
RED		  = \033[31;1m

SRC_FILES = main

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	$(OBJ)
			@make all -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(GREEN)Compilation successful!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(BLUE)Compiling, please wait.: $(RESET)$(addsuffix .c, $(SRC_FILES))"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@rm -frf $(OBJ_DIR)
			@make clean -C $(MLX42)
			@make all clean -C $(LIBFT)
			@echo "$(RED)Cleaning libraries MLX and LIBFT, please wait.$(RESET)"
			@echo "$(RED)Cleaning program executables, please wait.$(RESET)"

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@make fclean -C $(MLX42)
			@make fclean -C $(LIBFT)
			@echo "$(YELLOW)Cleaning libraries.$(RESET)"
			@echo "$(YELLOW)Cleaning program objects.$(RESET)"

re: fclean all
			@echo "$(MAGENTA)Program recompiled$(RESET)"

norm:
			@norminette $(SRC) $(LIBFT)
						
.PHONY: all clean fclean re norm
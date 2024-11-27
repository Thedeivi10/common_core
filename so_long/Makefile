# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 21:33:55 by davigome          #+#    #+#              #
#    Updated: 2024/11/27 19:32:35 by davigome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS_NAME	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
MLX42		= ./MLX42
LIBFT		= ./libft
INCLUDES	= -I$(MLX42)/include -I$(LIBFT)/include -Iincludes
LIBS		= -L$(MLX42)/build/MLX42/lib -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft

# Colores
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

SRC_DIR			= ./sources
SRC_BONUS_DIR	= ./sources_bonus
OBJ_DIR			= ./obj
OBJ_BONUS_DIR	= ./obj_bonus

SRC_FILES		= so_long.c \
					ft_checks_tools.c \
					ft_checks_tools_2.c \
					ft_checks_tools_3.c \
					ft_tools.c \
					ft_start_map.c \
					ft_free.c \
					ft_init_mlx.c \
					ft_moves.c \
					ft_images.c

SRC_BONUS_FILES = so_long_bonus.c

OBJS				= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJS_BONUS			= $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS_FILES:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.cc
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "$(GREEN)Executable for so_long launched successfully!$(RESET)"

$(BONUS_NAME): $(LIBFT)/libft.a  $(OBJS_BONUS)
	@$(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LIBS)
	@echo "$(GREEN)Bonus for so_long launched successfully!$(RESET)"

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)
	
all:$(NAME)

bonus: $(BONUS_NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

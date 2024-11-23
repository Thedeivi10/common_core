# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 21:33:55 by davigome          #+#    #+#              #
#    Updated: 2024/11/22 19:51:54 by davigome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS_NAME	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLX42		= ./MLX42
LIBFT		= ./libft
INCLUDES	= -I$(MLX42)/include -I$(LIBFT)/include -Iincludes
LIBS		= -L$(MLX42)/build/MLX42/lib -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft

SRC_DIR			= ./sources
SRC_BONUS_DIR	= ./sources_bonus
OBJ_DIR			= ./obj
OBJ_BONUS_DIR	= ./obj_bonus

SRC_FILES		= so_long.c

SRC_BONUS_FILES = so_long_bonus.c

OBJS				= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJS_BONUS			= $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS_FILES:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.cc
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(MLX42)/lib/libmlx42.a $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(BONUS_NAME): $(LIBFT)/libft.a $(MLX42)/lib/libmlx42.a $(OBJS_BONUS)
	@$(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LIBS)

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

$(MLX42)/lib/libmlx42.a:
	@echo "Compilando MLX42..."
	@mkdir -p $(MLX42)/lib
	@mkdir -p $(MLX42)/build
	@cmake -B $(MLX42)/build $(MLX42) -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY=$(MLX42)/lib
	@cmake --build $(MLX42)/build
	
all:$(NAME)

bonus: $(BONUS_NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

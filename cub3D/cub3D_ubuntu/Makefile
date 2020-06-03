# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/06/03 17:53:28 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** # 

NAME = cub3D

CUB_SRC = main.c \
	  is_valid_file.c \
	  valid_check_1.c \
	  valid_check_2.c \
	  init_game.c \
	  parsing_map_info.c \
	  parsing_map_grid.c \
	  open_img.c \
	  save_bmp.c \
	  error.c \
	  utils.c \
	  get_next_line.c \
	  get_next_line_utils.c 

ENGINE_SRC = update_player.c \
			 event_hook.c \
			 raycast_screen.c \
			 calculate_dist_from_wall.c \
			 fill_item_img.c \
			 fill_texture_floor_ceiling.c

CUB_DIR = ./srcs
ENGINE_DIR = ./engine
LIBFT_DIR = ./libs/libft
MLX_DIR = ./libs/minilibx_linux

HEADER = -I ./includes -I $(LIBFT_DIR) -I $(MLX_DIR)

CUB_SRCS = $(addprefix $(CUB_DIR)/, $(CUB_SRC))
ENGINE_SRCS = $(addprefix $(ENGINE_DIR)/, $(ENGINE_SRC))
SRCS = $(CUB_SRCS) $(ENGINE_SRCS)
OBJS = $(SRCS:%c=%o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)
# MAC OS option
#MLX_LIB = -lmlx -framework OpenGL -framework AppKit

# UBUNTU option
MLX_LIB = -lmlx -lX11 -lXext
FT_LIB = -lft

.SUFFIXES: .c .o
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	@cd $(LIBFT_DIR) ; make
	@cd $(MLX_DIR) ; make
	$(CC) $(CFLAGS) $^ -L $(MLX_DIR) $(MLX_LIB) -L $(LIBFT_DIR) $(FT_LIB) -lm -o $@

$.o: .c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS)

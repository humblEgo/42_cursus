# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/06/02 14:22:52 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = main.c \
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

ENGINE_SRC = raycast_screen.c \
			  calculate_dist_from_wall.c \
			  fill_texture_to_floor_ceiling.c \
			  fill_item_image.c \
			  update_player.c \
			  event_hook.c

SRCDIR = ./srcs
ENGINEDIR = ./engine
LIBDIR = ./libs/libft
MLXDIR = ./libs/minilibx
INCDIR = ./includes

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
ENGINE_SRCS = $(addprefix $(ENGINEDIR)/, $(ENGINE_SRC))

OBJS = $(SRCS:.c=.o)
ENGINE_OBJS = $(ENGINE_SRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)
HEADER = -I $(INCDIR) -I $(LIBDIR) -I $(MLXDIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
MLX = -mlx -X11 -Xext -lm -lft

.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADER) 

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONAY: all clean fclean re bonus

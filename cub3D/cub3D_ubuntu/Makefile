# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/06/02 12:11:31 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME = libft.a

LIBDIR = libs/libft
LIBFT_FLAGS = -L./libft -lft

OBJS = $(SRCS:%c=%o)
HEADER = libft.h

CC = gcc
# Ubuntu 18.04 option
CFLAGS = -Wall -Wextra -Werror -lmlx -X11 -Xext -lm -lft


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: all $(OBJS_BONUS)
	$(CC) $(CFLAGS) -c $(_bonus)
	ar rcs $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -include $(HEADER) 

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONAY: all clean fclean re bonus

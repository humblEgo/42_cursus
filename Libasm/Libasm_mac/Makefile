# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/06/11 15:29:11 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = ft_strlen.s \
	  ft_strcpy.s \
	  ft_strcmp.s \
	  ft_write.s \
	  ft_read.s \
	  ft_strdup.s

SRC_BONUS = ft_list_push_front.s \
			ft_list_sort.s \
			ft_list_size.s

SRCDIR = ./srcs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
SRCS_BONUS = $(addprefix $(SRCDIR)/, $(SRC_BONUS))
OBJS = $(SRCS:%s=%o)
OBJS_BONUS = $(SRCS_BONUS:%s=%o)
INC = ./includes

CC = gcc
NASM = nasm
NFLAGS_UBUNTU = -f elf64
NFLAGS_MAC = -f macho64

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: all $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

%.o: %.s
	$(NASM) $(NFLAGS_MAC) -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

test: re
	$(CC) -I$(INC) -o test main.c -L. -lasm

test_bonus: re_bonus
	$(CC) -I$(INC) -o test main_bonus.c -L. -lasm

.PHONAY: all clean fclean re bonus test test_bonus

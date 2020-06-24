# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/06/11 11:13:45 by iwoo             ###   ########.fr        #
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
			ft_list_size.s \
			ft_list_sort.s

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
	$(NASM) $(NFLAGS_UBUNTU) -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

test: re_bonus
	$(CC) -o test -I$(INC) test.c -L. -lasm -no-pie

print:
	echo "$(SRCS)"
	echo "$(OBJS)"

.PHONAY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/06/09 07:55:19 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = ft_strlen.s \
	  ft_strcpy.s \
	  ft_strcmp.s \
	  ft_write.s \
	  ft_read.s

#_bonus = ft_lstnew.c \

SRCDIR = ./srcs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(SRCS:%s=%o)
#OBJS_BONUS = $(_bonus:%s=%o)
INC = ./includes

CC = gcc
NASM = nasm
NFLAGS_UBUNTU = -f elf64
NFLAGS_MAC = -f macho64

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

#bonus: all $(OBJS_BONUS)
#	ar rcs $(NAME) $(OBJS_BONUS)

%.o: %.s
	$(NASM) $(NFLAGS_MAC) -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

test: re
	$(CC) -o test -I$(INC) test.c -L. -lasm

print:
	echo "$(SRCS)"
	echo "$(OBJS)"

.PHONAY: all clean fclean re bonus

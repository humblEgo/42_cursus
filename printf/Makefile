# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/03/08 12:43:53 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_printf_util.c \
	  ft_itoa_base_llu.c \
	  ft_strjoin_free_s2.c \
	  print_fmt_util.c \
	  print_fmt_util2.c \
	  check_fmt_util.c \
	  valid_util.c

LIBSRC = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strnstr.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c

SRCS = $(addprefix srcs/, $(SRC))
LIBSRCS = $(addprefix libs/, $(LIBSRC))
HEADER = -I includes

OBJ = $(SRCS:%.c=%.o)
LIBOBJ = $(LIBSRCS:%.c=%.o)
OBJDIR = objs

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ)
	ar rcs $@ $^

$(OBJ) : %.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(LIBOBJ) : %.o: %.c
	$(CC) $(CFLAGS) $(HEADER) $< -o $@

clean:
	rm -rf $(OBJ) $(LIBOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus

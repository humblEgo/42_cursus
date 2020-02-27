# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/02/27 19:34:34 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
_BONUS = bonus.a
SRCS = ft_memset.c \
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
	   ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew.c
OBJS = $(SRCS:%c=%o)
OBJS_BONUS = $(SRCS:%c=%o) $(SRCS_BONUS:%c=%o)
HEADER = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -include $(HEADER) 

bonus: $(_BONUS)
	mv $(_BONUS) $(NAME)

$(_BONUS): $(OBJS_BONUS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONAY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:57:59 by iwoo              #+#    #+#              #
#    Updated: 2020/03/10 13:52:02 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_printf_util.c \
	  print_fmts_1.c \
	  print_fmts_2.c \
	  print_fmt_util.c \
	  check_fmt_util.c \
	  put_value_util.c \
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

SRCDIR = srcs
INCDIR = includes
OBJDIR = objs
LIBDIR = libft

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
LIBSRCS = $(addprefix $(LIBDIR)/, $(LIBSRC))
HEADER = -I $(INCDIR) 

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBOBJ = $(LIBSRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJ)
	@ar rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p objs 
	@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@

$(LIBOBJ) : %.o: %.c
	@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@

clean:
	@rm -rf $(OBJS) $(LIBOBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -r $(OBJDIR)

re: fclean all

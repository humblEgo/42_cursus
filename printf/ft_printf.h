/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:37:07 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/06 21:43:32 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

#include <stdio.h> //should delete!

# define ASTERISK -2

typedef struct	s_flag
{
	int	minus;
	int zero;
	int	space;
	int	pound;
}				t_flag;

typedef struct s_format_info
{
	va_list	arg;
	t_flag	flag;
	int		width;
	int		prec;
	int		leng;
	char	spec;
}				t_fmt_info;

int	ft_printf(const char *, ...);
int	ft_putnstr_fd(char *str, int n, int fd);

#endif

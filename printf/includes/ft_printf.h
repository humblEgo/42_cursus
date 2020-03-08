/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:37:07 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 03:24:06 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

#include <stdio.h> //should delete!

# define INIT_VALUE -1
# define ASTERISK -2
# define ONLY_DOT_NO_PREC -3
# define MINUS_NUM_WITH_ASTERISK -4

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
	int		tmp_width;
	int		prec;
	int		leng;
	char	spec;
}				t_fmt_info;

int		ft_printf(const char *, ...);
void	init_fmt_info(t_fmt_info *info);

int		ft_putnstr_fd(char *str, int n, int fd);
int		is_numeric(char c);

int		check_spec(const char *fmt, t_fmt_info *info, int *i);
int		check_prec(const char *fmt, t_fmt_info *info, int *i);
int		check_width(const char *fmt, t_fmt_info *info, int *i);
int		check_flag(const char *fmt, t_fmt_info *info, int *i);

char	*ft_itoa_base_llu(unsigned long long n, char *base);
char	*ft_strjoin_free_s2(const char *s1, char *s2);

void	print_char(t_fmt_info *info, int *count);
void	print_str(t_fmt_info *info, int *count);
void	print_p_addr(t_fmt_info *info, int *count);
void	print_dec(t_fmt_info *info, int *count);
void	print_unsigned_int(t_fmt_info *info, int *count);
void	print_unsigned_hex(t_fmt_info *info, int *count);
void	print_percent(int *count);

int		is_valid_input(const char *fmt, t_fmt_info *tmp);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:37:07 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/11 17:31:20 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

#include <stdio.h>

# define FLAGS "-0# +"
# define SPECS "cspdiuxX%nf"
# define INIT_VALUE -1
# define ASTERISK -2
# define ONLY_DOT_NO_PREC -3
# define NEG_WITH_ASTERISK -4

typedef struct	s_flag
{
	int	minus;
	int zero;
	int pound;
	int	space;
	int	plus;
}				t_flag;

typedef struct	s_format_info
{
	va_list	arg;
	t_flag	flag;
	int		width;
	int		tmp_width;
	int		prec;
	int		prec_info;
	int		leng;
	char	spec;
	int		lh;
}				t_fmt_info;

/*
**		ft_printf.c
*/

int				ft_printf(const char *arg, ...);
void			init_fmt_info(t_fmt_info *info, int *i, int *cnt, char *stat);
int				check_fmt(const char *fmt, t_fmt_info *info, int *idx);
void			print_by_info(t_fmt_info *info, int *count);

/*
**		ft_printf_util.c
*/

int				ft_putnstr_fd(char *str, int n, int fd);
int				is_numeric(char c);
char			*ft_strjoin_free_s2(const char *s1, char *s2);
int				digit_size_llu(unsigned long long n, unsigned long long b_len);
char			*ft_itoa_base_llu(unsigned long long n, char *base);

/*
**		ft_printf_util2.c
*/

char			*ft_itoa_base_lli(long long int n, char *base);
int				digit_size_lli(long long int n, long long int base_len);

/*
**		check_fmt_util.c
*/

int				check_flag(const char *fmt, t_fmt_info *info, int *i);
int				check_width(const char *fmt, t_fmt_info *info, int *i);
int				check_prec(const char *fmt, t_fmt_info *info, int *i);
int				check_spec(const char *fmt, t_fmt_info *info, int *i);

/*
**		print_fmt_util.c
*/

void			set_if_asterisk(t_fmt_info *info);
void			set_addr_str(t_fmt_info *info, char **addr_str);
void			set_prec_width(t_fmt_info *info, int len, char *dec_str);
void			set_prefix(t_fmt_info *info, char **dec_str);
void			set_dec_str(t_fmt_info *info, char **dec_str, char *base);

/*
**		print_fmts_1.c
*/

void			print_char(t_fmt_info *info, int *count);
void			print_str(t_fmt_info *info, int *count);
void			print_p_addr(t_fmt_info *info, int *count);
void			print_dec(t_fmt_info *info, int *count);
void			print_unsigned_int(t_fmt_info *info, int *count);

/*
**		print_fmts_2.c
*/

void			print_unsigned_hex(t_fmt_info *info, int *count);
void			print_percent(t_fmt_info *info, int *count);
void			print_n(t_fmt_info *info, int *count);

/*
**		put_value_util.c
*/

void			put_prec_str_space(char *s, int len, int *cnt, t_fmt_info *inf);
void			put_space_prec_str(char *s, int len, int *cnt, t_fmt_info *inf);
void			put_space_sign_prec_str(char *d, int l, int *c, t_fmt_info *i);
void			put_sign_num(char *dec, int l, int *cnt, t_fmt_info *inf);
void			put_num(char *dec, int l, int *cnt, t_fmt_info *inf);

/*
**		valid_util.c
*/

int				check_valid(t_fmt_info *tmp);
int				is_valid_input(const char *fmt, t_fmt_info *tmp);

#endif

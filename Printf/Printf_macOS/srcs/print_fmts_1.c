/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmts_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/10 22:41:51 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_char(t_fmt_info *info, int *count)
{
	char	c;
	int		len;

	set_if_asterisk(info);
	c = va_arg(info->arg, int);
	len = 1;
	info->width -= len;
	if (info->flag.minus == 1)
	{
		*count += write(STDOUT_FILENO, &c, 1);
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
		*count += write(STDOUT_FILENO, &c, 1);
	}
}

void	print_str(t_fmt_info *info, int *count)
{
	char	*str;
	int		len;

	set_if_asterisk(info);
	if (!(str = va_arg(info->arg, char *)))
		str = "(null)";
	len = (int)ft_strlen(str);
	if (info->prec >= 0)
		len = (len > info->prec) ? (info->prec) : len;
	else if (info->prec == ONLY_DOT_NO_PREC)
		len = 0;
	info->width -= len;
	if (info->flag.minus == 1)
		put_prec_str_space(str, len, count, info);
	else
		put_space_prec_str(str, len, count, info);
}

void	print_p_addr(t_fmt_info *info, int *count)
{
	char				*addr_str;
	int					len;

	set_if_asterisk(info);
	set_addr_str(info, &addr_str);
	len = (int)ft_strlen(addr_str);
	if (info->prec >= 0)
		len = (len > info->prec) ? (info->prec) : len;
	info->width -= len;
	if (info->flag.minus == 1)
		put_prec_str_space(addr_str, len, count, info);
	else
		put_space_prec_str(addr_str, len, count, info);
}

void	print_dec(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;
	char	*base;

	base = "0123456789";
	set_if_asterisk(info);
	set_dec_str(info, &dec_str, base);
	set_prefix(info, &dec_str);
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' &&
			(info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;
	set_prec_width(info, len, dec_str);
	if (dec_str[0] == '-' || info->flag.space == 1 || info->flag.plus == 1)
		put_sign_num(dec_str, len, count, info);
	else
		put_num(dec_str, len, count, info);
	free(dec_str);
}

void	print_unsigned_int(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;
	char	*base;

	base = "0123456789";
	set_if_asterisk(info);
	set_dec_str(info, &dec_str, base);
	set_prefix(info, &dec_str);
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' &&
			(info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;
	set_prec_width(info, len, dec_str);
	if (info->flag.space == 1 || info->flag.plus == 1)
		put_sign_num(dec_str, len, count, info);
	else
		put_num(dec_str, len, count, info);
	free(dec_str);
}

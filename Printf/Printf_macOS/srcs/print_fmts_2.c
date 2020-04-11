/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmts_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/11 18:26:13 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_unsigned_hex(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;
	char	*base;

	set_if_asterisk(info);
	base = "";
	if (info->spec == 'x')
		base = "0123456789abcdef";
	else if (info->spec == 'X')
		base = "0123456789ABCDEF";
	set_dec_str(info, &dec_str, base);
	set_prefix(info, &dec_str);
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' && (info->prec == ONLY_DOT_NO_PREC ||
				info->prec == 0))
		len = 0;
	set_prec_width(info, len, dec_str);
	if (info->flag.space == 1 || info->flag.plus == 1)
		put_sign_num(dec_str, len, count, info);
	else
		put_num(dec_str, len, count, info);
	free(dec_str);
}

void	print_percent(t_fmt_info *info, int *count)
{
	char	*str;
	int		len;

	set_if_asterisk(info);
	str = "%";
	len = (int)ft_strlen(str);
	info->width -= len;
	if (info->flag.minus == 1)
		put_prec_str_space(str, len, count, info);
	else
		put_space_prec_str(str, len, count, info);
}

void	print_n(t_fmt_info *info, int *count)
{
	int	*res;

	res = va_arg(info->arg, int *);
	write(1, "", 0);
	*res = *count;
}

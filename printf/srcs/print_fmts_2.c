/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmts_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 21:30:30 by iwoo             ###   ########.fr       */
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
	if (info->spec == 'x')
		base = "0123456789abcdef";
	else if (info->spec == 'X')
		base = "0123456789ABCDEF";
	dec_str = ft_itoa_base_llu((unsigned long long)va_arg(info->arg, unsigned int), base);
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' && (info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;
	set_prec_width(info, len, dec_str);
	put_plus_num(dec_str, len, count, info);
	free(dec_str);
}

void	print_percent(int *count)
{
	*count += write(STDOUT_FILENO, "%", 1); 
}

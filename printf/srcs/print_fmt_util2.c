/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 02:35:43 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_unsigned_hex(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;
	char	*base;

	if (info->width == ASTERISK)
	{
		info->tmp_width = va_arg(info->arg, int);
		if (info->tmp_width == -2147483648)
			return ;
		else if (info->tmp_width < 0)
		{
			info->width = info->tmp_width * (-1);
			info->flag.minus = 1;
		}
		else
			info->width = info->tmp_width;
	}
	if (info->prec == ASTERISK)
		info->prec = va_arg(info->arg, int);  
	if (info->spec == 'x')
		base = "0123456789abcdef";
	else if (info->spec == 'X')
		base = "0123456789ABCDEF";
	dec_str = ft_itoa_base_llu((unsigned long long)va_arg(info->arg, unsigned int), base);
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' && (info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;
	if (info->prec != INIT_VALUE)
	{
		info->prec = (info->prec > len) ? info->prec - len : 0;
		info->width -= info->prec + len;
	}
	else
		info->width -= len;
	if (info->flag.minus == 1)
	{
		while (info->prec-- > 0)
			*count += write(STDOUT_FILENO, "0", 1);
		*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
	}
	else if(info->flag.zero == 1)
	{
		if (info->prec != INIT_VALUE)
		{
			while (info->width-- > 0)
				*count += write(STDOUT_FILENO, " ", 1);
			while (info->prec-- > 0)
				*count += write(STDOUT_FILENO, "0", 1);
			*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
		}
		else
		{
			while (info->width-- > 0)
				*count += write(STDOUT_FILENO, "0", 1);
			*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
		}
	}
	else
	{
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
		while (info->prec-- > 0)
			*count += write(STDOUT_FILENO, "0", 1);
		*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
	}
	free(dec_str);
}

void	print_percent(int *count)
{
	*count += write(STDOUT_FILENO, "%", 1); 
}

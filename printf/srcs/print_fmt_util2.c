/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/08 16:54:29 by iwoo             ###   ########.fr       */
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
		info->width = va_arg(info->arg, int);
	if (info->prec == ASTERISK)
		info->prec = va_arg(info->arg, int);  
	if (info->spec == 'x')
		base = "0123456789abcdef";
	else if (info->spec == 'X')
		base = "0123456789ABCDEF";
	dec_str = ft_itoa_base_llu((unsigned long long)va_arg(info->arg, int), base);
	len = (int)ft_strlen(dec_str);
	info->width -= len;
	if (info->flag.minus == 1)
	{
		*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
	}
	else if(info->flag.zero == 1)
	{
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, "0", 1);
		*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
	}
	else
	{
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
		*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
	}
	free(dec_str);
}

void	print_percent(int *count)
{
	*count += write(STDOUT_FILENO, "%", 1); 
}

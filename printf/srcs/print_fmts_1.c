/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmts_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 21:29:27 by iwoo             ###   ########.fr       */
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
		str = (info->prec == INIT_VALUE) || (info->prec >= 6) ? "(null)" : "";
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
	if (!(ft_strncmp(addr_str, "(nil)", 5)))
		*count += ft_putnstr_fd(addr_str, 5, STDOUT_FILENO);
	else if (info->flag.minus == 1)
		put_prec_str_space(addr_str, len, count, info);
	else
		put_space_prec_str(addr_str, len, count, info);
	if (ft_strncmp(addr_str, "(nil)", 5))
		free(addr_str);
}
		
void	print_dec(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;

	set_if_asterisk(info);
	dec_str = ft_itoa(va_arg(info->arg, int));
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' && (info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;
	set_prec_width(info, len, dec_str);
	if (dec_str[0] == '-')
		put_minus_num(dec_str, len, count, info);
	else
		put_plus_num(dec_str, len, count, info);
	free(dec_str);
}

void	print_unsigned_int(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;
	char	*base;

	base = "0123456789";
	set_if_asterisk(info);
	dec_str = ft_itoa_base_llu((unsigned long long)va_arg(info->arg, unsigned int), base);
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' && (info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;	
	set_prec_width(info, len, dec_str);
	put_plus_num(dec_str, len, count, info);
	free(dec_str);
}

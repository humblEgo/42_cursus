/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 03:31:05 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_char(t_fmt_info *info, int *count)
{
	char	c;
	int		len;

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
	{
		info->prec = va_arg(info->arg, int);
		if (info->prec == ONLY_DOT_NO_PREC)
			info->prec = MINUS_NUM_WITH_ASTERISK;
	}
	if (!(str = va_arg(info->arg, char *)))
		str = (info->prec == INIT_VALUE) || (info->prec >= 6) ? "(null)" : "";
	len = (int)ft_strlen(str);
	if (info->prec >= 0)
		len = (len > info->prec) ? (info->prec) : len;
	else if (info->prec == ONLY_DOT_NO_PREC)
		len = 0;
	info->width -= len;
	if (info->flag.minus == 1)
	{
		*count += ft_putnstr_fd(str, len, STDOUT_FILENO);
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
		*count += ft_putnstr_fd(str, len, STDOUT_FILENO);
	}
}

void	print_p_addr(t_fmt_info *info, int *count)
{
	void				*p;
	unsigned long long	addr;
	char				*addr_str;
	int					len;

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
	if (!(p = va_arg(info->arg, void *)))
		addr_str = "(nil)";
	else
	{
		addr = (unsigned long long)p;
		addr_str = ft_itoa_base_llu(addr, "0123456789abcdef");
		addr_str = ft_strjoin_free_s2("0x", addr_str);
	}
	len = (int)ft_strlen(addr_str);
	if (info->prec >= 0)
		len = (len > info->prec) ? (info->prec) : len;
//	else if (info->prec == ONLY_DOT_NO_PREC)
//		len = 0;
	info->width -= len;
	if (!(ft_strncmp(addr_str, "(nil)", 5)))
		*count += ft_putnstr_fd(addr_str, 5, STDOUT_FILENO);
	else if (info->flag.minus == 1)
	{
		*count += ft_putnstr_fd(addr_str, len, STDOUT_FILENO);
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
		*count += ft_putnstr_fd(addr_str, len, STDOUT_FILENO);
	}
	if (ft_strncmp(addr_str, "(nil)", 5))
		free(addr_str);
}
		
void	print_dec(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;

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
	dec_str = ft_itoa(va_arg(info->arg, int));
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' && (info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;
	if (info->prec != INIT_VALUE)
	{
		if (dec_str[0] == '-')
			info->prec = info->prec > len ? info->prec - len + 1 : 0;
		else
			info->prec = info->prec > len ? info->prec - len : 0;
		info->width -= info->prec + len;
	}
	else
		info->width -= len;
	if (info->flag.minus == 1)
	{
		if (dec_str[0] == '-')
		{
			*count += write(STDOUT_FILENO, &dec_str[0], 1);
			while (info->prec-- > 0)
				*count += write(STDOUT_FILENO, "0", 1);
			*count += ft_putnstr_fd(&dec_str[1], len, STDOUT_FILENO);
			while (info->width-- > 0)
				*count += write(STDOUT_FILENO, " ", 1);
		}
		else
		{
			while (info->prec-- > 0)
				*count += write(STDOUT_FILENO, "0", 1);
			*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
			while (info->width-- > 0)
				*count += write(STDOUT_FILENO, " ", 1);
		}
	}
	else if (info->flag.zero == 1)
	{
		if (info->prec != INIT_VALUE)
		{
			if (dec_str[0] == '-')
			{
				while (info->width-- > 0)
					*count += write(STDOUT_FILENO, " ", 1);
				*count += write(STDOUT_FILENO, &dec_str[0], 1);
				while (info->prec-- > 0)
					*count += write(STDOUT_FILENO, "0", 1);
				*count += ft_putnstr_fd(&dec_str[1], len, STDOUT_FILENO);
			}
			else
			{
				while (info->width-- > 0)
					*count += write(STDOUT_FILENO, " ", 1);
				while (info->prec-- > 0)
					*count += write(STDOUT_FILENO, "0", 1);
				*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
			}
		}
		else
		{
			if (dec_str[0] == '-')
			{
				*count += write(STDOUT_FILENO, &dec_str[0], 1);
				while (info->width-- > 0)
					*count += write(STDOUT_FILENO, "0", 1);
				*count += ft_putnstr_fd(&dec_str[1], len, STDOUT_FILENO);
			}
			else
			{
				while (info->width-- > 0)
					*count += write(STDOUT_FILENO, "0", 1);
				*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
			}
		}
	}
	else
	{
		if (dec_str[0] == '-' && info->prec != INIT_VALUE)
		{
			while (info->width-- > 0)
				*count += write(STDOUT_FILENO, " ", 1);
			*count += write(STDOUT_FILENO, &dec_str[0], 1);
			while (info->prec-- > 0)
				*count += write(STDOUT_FILENO, "0", 1);
			*count += ft_putnstr_fd(&dec_str[1], len, STDOUT_FILENO);
		}
		else
		{
			while (info->width-- > 0)
				*count += write(STDOUT_FILENO, " ", 1);
			while (info->prec-- > 0)
				*count += write(STDOUT_FILENO, "0", 1);
			*count += ft_putnstr_fd(dec_str, len, STDOUT_FILENO);
		}
	}
	free(dec_str);
}

void	print_unsigned_int(t_fmt_info *info, int *count)
{
	char	*dec_str;
	int		len;
	char	*base;

	base = "0123456789";
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
	dec_str = ft_itoa_base_llu((unsigned long long)va_arg(info->arg, unsigned int), base);
	len = (int)ft_strlen(dec_str);
	if (dec_str[0] == '0' && (info->prec == ONLY_DOT_NO_PREC || info->prec == 0))
		len = 0;	
	if (info->prec != INIT_VALUE)
	{
		info->prec = (info->prec) > len ? info->prec - len : 0;
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

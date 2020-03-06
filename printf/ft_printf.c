/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:51 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/06 23:55:18 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	init_fmt_info(t_fmt_info *info)
{
	info->width = 0;
	info->prec = -1;
	info->leng = 0;
	info->spec = 0;
	info->flag.minus = 0;
	info->flag.zero = 0;
}

int	check_flag(const char *fmt, t_fmt_info *info, int *i)
{
	char	*flags;

	flags = "-0";
	if (ft_strchr(flags, fmt[*i]))
	{
		if (fmt[*i] == '-')
			info->flag.minus = 1;
		else if (fmt[*i] == '0')
			info->flag.zero = 1;
		(*i)++;
		return (1);
	}
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_width(const char *fmt, t_fmt_info *info, int *i)
{
	if (fmt[*i] == '*')
	{
		info->width = ASTERISK;
		(*i)++;
		return (1);
	}
	else if (is_numeric(fmt[*i]))
	{
		info->width = ft_atoi(&fmt[*i]);
		while (is_numeric(fmt[*i]))
			(*i)++;
		return (1);
	}
	return (0);
}

int	check_prec(const char *fmt, t_fmt_info *info, int *i)
{
	if (fmt[*i] == '.')
	{
		(*i)++;
		if (fmt[*i] == '*')
		{
			info->prec = ASTERISK;
			(*i)++;
			return (1);
		}
		else if (is_numeric(fmt[*i]))
		{
			info->prec = ft_atoi(&fmt[*i]);
			while (is_numeric(fmt[*i]))
				(*i)++;
			return (1);
		}
	}
	return (0);
}

int	check_spec(const char *fmt, t_fmt_info *info, int *i)
{
	char	*specs;

	specs = "cspdiuxX%";
	if (ft_strchr(specs, fmt[*i]))
	{
		info->spec = fmt[*i];
		return (1);
	}
	return (-1);
}

void	print_char(t_fmt_info *info, int *count)
{
	char	c;
	int		len;

	if (info->width == ASTERISK)
		info->width = va_arg(info->arg, int); 
	c = va_arg(info->arg, int);
	len = 1;
	info->width -= len;
	if (info->flag.minus == 1)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		*count++;
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while (info->width-- > 0)
			*count += write(STDOUT_FILENO, " ", 1);
		ft_putchar_fd(c, STDOUT_FILENO);
		*count++;
	}
}

void	print_str(t_fmt_info *info, int *count)
{
	char	*str;
	int		len;

	if (info->width == ASTERISK)
		info->width = va_arg(info->arg, int);
	if (info->prec == ASTERISK)
		info->prec = va_arg(info->arg, int);  
	str = va_arg(info->arg, char *);
	len = (int)ft_strlen(str);
	if (info->prec >= 0)
		len = len > info->prec ? (info->prec) : len;
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
	void	*addr;

	addr = va_arg(info->arg, void *);
	

}
		
void	print_format(t_fmt_info *info, int *count)
{
	if (info->spec == 'c')
		print_char(info, count);
	else if (info->spec == 's')
		print_str(info, count);
	else if (info->spec == 'p')
		print_p_addr(info, count);
/*	else if (info->spec == 'd')
		print_format_p(info, count);
	else if (info->spec == 'i')
		print_format_i(info, count);
	else if (info->spec == 'u')
		print_format_u(info, count);
	else if (info->spec == 'x')
		print_format_x(info, count);
	else if (info->spec == 'X')
		print_format_X(info, count); */
}

void	print_by_info(t_fmt_info *info, int *count)
{
/*	if (info->flag.minus == 1)
	{
		print_format(info, count);
		print_padding(info, count, ' ');
	}
	else if (info->flag.zero == 1)
		print_padding(info, count, '0');
	else if (info->flag.space == 1)
		print_padding(info, count, ' '); */
	print_format(info, count);
}

int	ft_printf(const char *fmt, ...)
{
	int			i;
	int			count;
	int			spec_offset;
	t_fmt_info	info;
	int			temp = 0;

	i = 0;
	count = 0;
	init_fmt_info(&info);
	va_start(info.arg, fmt);
	if (ft_strlen(fmt) == 0)
		return (-1);
/*	if (!(is_valid_input(fmt, &info)))
		return (-1); */
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '%')
				count += write(STDOUT_FILENO, "%", 1);
			else
			{
				temp = check_flag(fmt, &info, &i);
				temp = check_width(fmt, &info, &i);
				temp = check_prec(fmt, &info, &i);
				temp = check_spec(fmt, &info, &i);
				print_by_info(&info, &count);
			}
		}
		else 
		{
			count += write(STDOUT_FILENO, &fmt[i], 1);
		}
		i++; 
	} 
	return (count);
}

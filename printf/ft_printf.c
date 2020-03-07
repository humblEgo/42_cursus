/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:51 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/07 16:29:44 by iwoo             ###   ########.fr       */
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

void	print_by_info(t_fmt_info *info, int *count)
{
	if (info->spec == 'c')
		print_char(info, count);
	else if (info->spec == 's')
		print_str(info, count);
	else if (info->spec == 'p')
		print_p_addr(info, count);
	else if (info->spec == 'd')
		print_dec(info, count);
	else if (info->spec == 'i')
		print_dec(info, count);
	else if (info->spec == 'u')
		print_unsigned_int(info, count);
	else if (info->spec == 'x')
		print_unsigned_hex(info, count);
	else if (info->spec == 'X')
		print_unsigned_hex(info, count); 
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
				init_fmt_info(&info);
			}
		}
		else 
			count += write(STDOUT_FILENO, &fmt[i], 1);
		i++; 
	} 
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:51 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 02:58:05 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	init_fmt_info(t_fmt_info *info)
{
	info->width = -1;
	info->tmp_width = 0;
	info->prec = -1;
	info->leng = -1;
	info->spec = -1;
	info->flag.minus = -1;
	info->flag.zero = -1;
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
	else if (info->spec == '%')
		print_percent(count); 
}

int	ft_printf(const char *fmt, ...)
{
	int			i;
	int			count;
	t_fmt_info	info;
	t_fmt_info	tmp;

	i = 0;
	count = 0;
	init_fmt_info(&info);
	va_start(info.arg, fmt);
	va_copy(tmp.arg, info.arg);
	if (ft_strlen(fmt) == 0)
		return (0);
	if (!(is_valid_input(fmt, &tmp)))
		return (-1); 
	va_end(tmp.arg);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			check_flag(fmt, &info, &i);
			check_width(fmt, &info, &i);
			check_prec(fmt, &info, &i);
			if (check_spec(fmt, &info, &i) < 0)
				return (0);
			print_by_info(&info, &count);
			init_fmt_info(&info);
			if (fmt[i] == '\0')
				break ;
		}
		else 
			count += write(STDOUT_FILENO, &fmt[i], 1);
		i++;
	} 
	va_end(info.arg);
	return (count);
}

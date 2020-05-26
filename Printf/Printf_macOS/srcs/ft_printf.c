/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.co.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:42:27 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/11 16:27:27 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	init_fmt_info(t_fmt_info *info, int *idx, int *count, char *status)
{
	if (!(ft_strncmp("start", status, 6)))
	{
		*idx = -1;
		*count = 0;
	}
	info->width = -1;
	info->tmp_width = 0;
	info->prec = -1;
	info->prec_info = 0;
	info->leng = -1;
	info->spec = -1;
	info->lh = 0;
	info->flag.minus = -1;
	info->flag.zero = -1;
	info->flag.pound = -1;
	info->flag.space = -1;
	info->flag.plus = -1;
}

int		check_fmt(const char *fmt, t_fmt_info *info, int *idx)
{
	check_flag(fmt, info, idx);
	check_width(fmt, info, idx);
	check_prec(fmt, info, idx);
	if (check_spec(fmt, info, idx) < 0)
		return (0);
	if (fmt[*idx] == '\0')
		return (0);
	return (1);
}

void	print_by_info(t_fmt_info *info, int *count)
{
	if (info->spec == 'c')
		print_char(info, count);
	else if (info->spec == 's')
		print_str(info, count);
	else if (info->spec == 'p')
		print_p_addr(info, count);
	else if (info->spec == 'd' || info->spec == 'i')
		print_dec(info, count);
	else if (info->spec == 'u')
		print_unsigned_int(info, count);
	else if (info->spec == 'x' || info->spec == 'X')
		print_unsigned_hex(info, count);
	else if (info->spec == '%')
		print_percent(info, count);
	else if (info->spec == 'n')
		print_n(info, count);
}

int		ft_printf(const char *fmt, ...)
{
	int			i;
	int			count;
	t_fmt_info	info;

	init_fmt_info(&info, &i, &count, "start");
	va_start(info.arg, fmt);
	if (!(is_valid_input(fmt, &info)))
		return (0);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (!(check_fmt(fmt, &info, &i)))
				break ;
			print_by_info(&info, &count);
			init_fmt_info(&info, &i, &count, "in_progress");
		}
		else
			count += write(STDOUT_FILENO, &fmt[i], 1);
	}
	va_end(info.arg);
	return (count);
}

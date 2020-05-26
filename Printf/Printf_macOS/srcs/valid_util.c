/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:39:10 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/11 18:26:26 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	check_valid(t_fmt_info *tmp)
{
	if (tmp->spec == 'c')
	{
		if (tmp->flag.zero != INIT_VALUE)
			return (0);
	}
	else if (tmp->spec == 's')
	{
		if (tmp->flag.zero != INIT_VALUE)
			return (0);
	}
	else if (tmp->lh != 0)
	{
		if (tmp->lh != 'l' && tmp->lh != 'l' + 'l' &&
				tmp->lh != 'h' && tmp->lh != 'h' + 'h')
			return (0);
	}
	return (1);
}

int	is_valid_input(const char *fmt, t_fmt_info *info)
{
	int			i;
	int			useless_count;
	t_fmt_info	tmp;

	init_fmt_info(&tmp, &i, &useless_count, "start");
	va_copy(tmp.arg, info->arg);
	if (ft_strlen(fmt) == 0)
		return (0);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (!(check_fmt(fmt, &tmp, &i)))
				return (0);
			if (!(check_valid(&tmp)))
				return (0);
			init_fmt_info(&tmp, &i, &useless_count, "in_progress");
		}
	}
	va_end(tmp.arg);
	return (1);
}

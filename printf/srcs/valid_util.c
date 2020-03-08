/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:39:10 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 02:19:25 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	check_valid(t_fmt_info *tmp)
{
	if (tmp->spec == 'c')
	{
		if (tmp->prec != INIT_VALUE)
			return (0);
		if (tmp->flag.zero != INIT_VALUE)
			return (0);
	}
	else if (tmp->spec == 's')
	{
		if (tmp->flag.zero != INIT_VALUE)
			return (0);
	}
	else if (tmp->spec == 'p')
	{
//		if (tmp->prec != INIT_VALUE)
//			return (0);
	}
	else if (tmp->spec == 'd' || tmp->spec == 'i' || 
			tmp->spec == 'u' || tmp->spec == 'x' || tmp->spec == 'X')
	{
//		if (tmp->flag.zero != INIT_VALUE && tmp->prec != INIT_VALUE)
//			return (0);
	}
	return (1);
}

int	is_valid_input(const char *fmt, t_fmt_info *tmp)
{
	int	i;

	i = 0;
	init_fmt_info(tmp);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '%')
				continue ;
			else
			{
				check_flag(fmt, tmp, &i);
				check_width(fmt, tmp, &i);
				check_prec(fmt, tmp, &i);
				check_spec(fmt, tmp, &i);
				if (!(check_valid(tmp)))
					return (0);
				init_fmt_info(tmp);
			}
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fmt_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:15:05 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/08 22:06:59 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
		else
		{
			info->prec = 0;
			return (-1);
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

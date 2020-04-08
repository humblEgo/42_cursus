/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fmt_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:15:05 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/08 21:39:52 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	check_flag(const char *fmt, t_fmt_info *info, int *i)
{
	int		res;
	char	*flags;

	res = 0;
	flags = FLAGS;
	while (ft_strchr(flags, fmt[*i]))
	{
		if (fmt[*i] == '-')
			info->flag.minus = 1;
		else if (fmt[*i] == '0')
			info->flag.zero = 1;
		else if (fmt[*i] == '#')
			info->flag.pound = 1;
		else if (fmt[*i] == ' ')
			info->flag.space = 1;
		else if (fmt[*i] == '+')
			info->flag.plus = 1;
		(*i)++;
		res = 1;
	}
	return (res);
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
			info->prec = ONLY_DOT_NO_PREC;
			return (-1);
		}
	}
	return (0);
}

int	check_spec(const char *fmt, t_fmt_info *info, int *i)
{
	char	*specs;
	char	*specs_lh;

	specs = SPECS;
	specs_lh = "lh";
	while (fmt[*i] != '\0' && (ft_strchr(specs, fmt[*i]) ||
				ft_strchr(specs_lh, fmt[*i])))
	{
		info->spec = ft_strchr(specs, fmt[*i]) ? fmt[*i] : INIT_VALUE;
		if (ft_strchr(specs_lh, fmt[*i]))
		{
			info->lh = fmt[*i] == 'l' ? info->lh + 'l' : info->lh + 'h';
			if (fmt[(*i) + 1] != '\0' &&
					(ft_strchr(specs, fmt[(*i) + 1]) ||
					ft_strchr(specs_lh, fmt[(*i) + 1])))
				(*i)++;
			else
				break ;
		}
		else
			break ;
	}
	return ((info->spec != INIT_VALUE) ? 1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:35:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/10 22:52:39 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	set_if_asterisk(t_fmt_info *info)
{
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
}

void	set_addr_str(t_fmt_info *info, char **addr_str)
{
	void				*p;
	unsigned long long	addr;

	if (!(p = va_arg(info->arg, void *)))
	{
		if (info->prec == ONLY_DOT_NO_PREC)
			*addr_str = "0x";
		else
			*addr_str = "0x0";
	}
	else
	{
		addr = (unsigned long long)p;
		*addr_str = ft_itoa_base_llu(addr, "0123456789abcdef");
		*addr_str = ft_strjoin_free_s2("0x", *addr_str);
	}
}

void	set_prec_width(t_fmt_info *info, int len, char *dec_str)
{
	if (info->prec != INIT_VALUE)
	{
		if (dec_str[0] == '-' || info->flag.space == 1 ||
				info->flag.plus == 1)
			info->prec = (info->prec > len - 1) ? info->prec - len + 1 : 0;
		else
			info->prec = (info->prec > len) ? info->prec - len : 0;
		info->width -= info->prec + len;
	}
	else
		info->width -= len;
}

void	set_prefix(t_fmt_info *info, char **dec_str)
{
	if (*dec_str[0] != '-' && info->flag.space == 1)
		*dec_str = ft_strjoin_free_s2(" ", *dec_str);
	else if (*dec_str[0] != '-' && info->flag.plus == 1)
		*dec_str = ft_strjoin_free_s2("+", *dec_str);
	else if (info->flag.pound == 1)
	{
		if (info->spec == 'X')
			*dec_str = ft_strjoin_free_s2("0X", *dec_str);
		else if (info->spec == 'x')
			*dec_str = ft_strjoin_free_s2("0x", *dec_str);
	}
}

void	set_dec_str(t_fmt_info *info, char **dec_str, char *base)
{
	unsigned long long	tmp_llu;
	long long int		tmp_lli;

	if (info->spec == 'd' || info->spec == 'i')
	{
		if (info->lh == 'l')
			tmp_lli = (long long int)va_arg(info->arg, long int);
		else if (info->lh == 'l' + 'l')
			tmp_lli = (long long int)va_arg(info->arg, long long int);
		else
			tmp_lli = (long long int)va_arg(info->arg, int);
		*dec_str = ft_itoa_base_lli(tmp_lli, base);
	}
	else
	{
		if (info->lh == 'l')
			tmp_llu = (unsigned long long)va_arg(info->arg, unsigned long);
		else if (info->lh == 'l' + 'l')
			tmp_llu = (unsigned long long)va_arg(info->arg, unsigned long long);
		else
			tmp_llu = (unsigned long long)va_arg(info->arg, unsigned int);
		*dec_str = ft_itoa_base_llu(tmp_llu, base);
	}
}

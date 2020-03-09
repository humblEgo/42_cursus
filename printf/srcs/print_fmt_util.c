/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:35:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 21:32:19 by iwoo             ###   ########.fr       */
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
		*addr_str = "(nil)";
	else
	{
		addr = (unsigned long long)p;
		*addr_str = ft_itoa_base_llu(addr, "0123456789abcdef");
		*addr_str = ft_strjoin_free_s2("0x", *addr_str);
	}
}

void	set_prec_width(t_fmt_info *info, int len, char *dec_str)
{
	if (info->prec != INIT_VALUE) //u, d
	{
		if (dec_str[0] == '-')
			info->prec = (info->prec > len) ? info->prec - len + 1 : 0;
		else
			info->prec = (info->prec) > len ? info->prec - len : 0;
		info->width -= info->prec + len;
	}
	else
		info->width -= len;
}

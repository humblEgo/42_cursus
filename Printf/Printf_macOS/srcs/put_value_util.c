/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_value_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:21:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/11 18:15:36 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	put_prec_str_space(char *str, int len, int *count, t_fmt_info *info)
{
	if (info->spec == 'd' || info->spec == 'i' || info->spec == 'u' ||
			info->spec == 'x' || info->spec == 'X')
		while (info->prec-- > 0)
			*count += write(STDOUT_FILENO, "0", 1);
	if ((info->flag.plus == 1 || info->flag.space == 1) &&
			*str == '0')
		*count += write(1, " ", 1);
	else
		*count += ft_putnstr_fd(str, len, STDOUT_FILENO);
	while (info->width-- > 0)
		*count += write(STDOUT_FILENO, " ", 1);
}

void	put_space_prec_str(char *str, int len, int *count, t_fmt_info *info)
{
	while (info->width-- > 0)
	{
		if (info->flag.zero == 1 && (info->spec == '%' ||
						info->prec_info == NEG_WITH_ASTERISK))
			*count += write(STDOUT_FILENO, "0", 1);
		else
			*count += write(STDOUT_FILENO, " ", 1);
	}
	if (info->spec == 'd' || info->spec == 'i' || info->spec == 'u' ||
			info->spec == 'x' || info->spec == 'X')
		while (info->prec-- > 0)
			*count += write(STDOUT_FILENO, "0", 1);
	*count += ft_putnstr_fd(str, len, STDOUT_FILENO);
}

void	put_space_sign_prec_str(char *dec, int len, int *cnt, t_fmt_info *info)
{
	if (info->prec != INIT_VALUE &&
			!((info->flag.zero == 1 && info->prec_info == NEG_WITH_ASTERISK)))
		while (info->width-- > 0)
			*cnt += write(STDOUT_FILENO, " ", 1);
	*cnt += write(STDOUT_FILENO, &dec[0], 1);
	if (info->flag.zero == 1 && (info->prec == INIT_VALUE ||
			(info->flag.zero == 1 && info->prec_info == NEG_WITH_ASTERISK)))
		while (info->width-- > 0)
			*cnt += write(STDOUT_FILENO, "0", 1);
	while (info->prec-- > 0)
		*cnt += write(STDOUT_FILENO, "0", 1);
	if ((info->flag.plus == 1 || info->flag.space == 1) &&
			dec[0] == '0')
		*cnt += write(1, " ", 1);
	else
		*cnt += ft_putnstr_fd(&dec[1], len, STDOUT_FILENO);
}

void	put_sign_num(char *dec, int len, int *count, t_fmt_info *info)
{
	if (info->flag.minus == 1)
	{
		*count += write(STDOUT_FILENO, &dec[0], 1);
		put_prec_str_space(&dec[1], len, count, info);
	}
	else if (info->flag.zero == 1)
		put_space_sign_prec_str(dec, len, count, info);
	else
	{
		if (info->prec != INIT_VALUE)
			put_space_sign_prec_str(dec, len, count, info);
		else
			put_space_prec_str(dec, len, count, info);
	}
}

void	put_num(char *dec, int len, int *count, t_fmt_info *info)
{
	if (info->flag.minus == 1)
		put_prec_str_space(dec, len, count, info);
	else if (info->flag.zero == 1)
	{
		if (info->prec != INIT_VALUE)
			put_space_prec_str(dec, len, count, info);
		else
		{
			while (info->width-- > 0)
				*count += write(STDOUT_FILENO, "0", 1);
			*count += ft_putnstr_fd(dec, len, STDOUT_FILENO);
		}
	}
	else
		put_space_prec_str(dec, len, count, info);
}

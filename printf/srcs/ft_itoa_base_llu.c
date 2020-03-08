/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_llu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:03:20 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/07 01:24:24 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	digit_size(unsigned long long n, unsigned long long base_len)
{
	int	digit_cnt;

	digit_cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base_len;
		digit_cnt++;
	}
	return (digit_cnt);
}

char	*ft_itoa_base_llu(unsigned long long n, char *base)
{
	char				*res;
	int					arr_size;
	unsigned long long	base_len;

	base_len = (unsigned long long)ft_strlen(base);
	arr_size = digit_size(n, base_len);
	base_len = (unsigned long long)ft_strlen(base);
	if (!(res = (char *)malloc(sizeof(char) * (arr_size + 1))))
		return (NULL);
	res[arr_size] = '\0';
	while (--arr_size > -1)
	{
		res[arr_size] = base[(int)(n % base_len)];
		n /= base_len;
		if (n == 0)
			break ;
	}
	return (res);
}

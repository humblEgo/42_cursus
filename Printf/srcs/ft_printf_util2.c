/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:27:20 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/08 21:10:36 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		digit_size_lli(long long int n, long long int bs_len)
{
	int	digit_cnt;

	digit_cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= bs_len;
		digit_cnt++;
	}
	return (digit_cnt);
}

char	*ft_itoa_base_lli(long long int n, char *base)
{
	char				*res;
	int					arr_size;
	long long int		b_len;

	b_len = (long long int)ft_strlen(base);
	arr_size = n < 0 ? digit_size_lli(n, b_len) + 1 : digit_size_lli(n, b_len);
	if (!(res = (char *)malloc(sizeof(char) * (arr_size + 1))))
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[arr_size] = '\0';
	while (--arr_size > -1)
	{
		res[arr_size] = base[(int)(n % b_len)];
		n /= b_len;
		if (n == 0)
			break ;
	}
	return (res);
}

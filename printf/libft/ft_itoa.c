/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:03:20 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/27 14:44:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_size(unsigned int n)
{
	int	digit_cnt;

	digit_cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digit_cnt++;
	}
	return (digit_cnt);
}

static int	get_arr_size(int n)
{
	int	arr_size;

	arr_size = 0;
	if (n < 0)
		arr_size = digit_size((unsigned int)(n * (-1))) + 1;
	else
		arr_size = digit_size((unsigned int)n);
	return (arr_size);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				arr_size;
	unsigned int	tmp;

	arr_size = get_arr_size(n);
	if (!(res = (char *)malloc(sizeof(char) * (arr_size + 1))))
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		tmp = (unsigned int)(n * (-1));
	}
	else
		tmp = n;
	res[arr_size] = '\0';
	while (--arr_size > -1)
	{
		res[arr_size] = (int)((tmp % 10) + '0');
		tmp /= 10;
		if (tmp == 0)
			break ;
	}
	return (res);
}

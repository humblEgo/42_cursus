/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:02:43 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/26 14:49:29 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign(char *tmp)
{
	if (*tmp == '+' || *tmp == '-')
		return (1);
	return (0);
}

static int	is_numeric(char *tmp)
{
	if (*tmp >= '0' && *tmp <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	*tmp;
	int		sign;
	int		res;

	tmp = (char *)nptr;
	sign = 1;
	res = 0;
	if (is_sign(tmp))
	{
		if (*tmp == '-')
			sign = -1;
		tmp++;
	}
	while (*tmp && is_numeric(tmp))
	{
		res *= 10;
		res += sign * (int)(*tmp - '0');
		tmp++;
	}
	return (res);
}

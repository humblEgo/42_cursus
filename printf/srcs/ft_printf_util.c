/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:27:20 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/07 16:18:02 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putnstr_fd(char	*str, int n, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i] && i < n)
		count += write(1, &str[i], fd);
	return (count);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
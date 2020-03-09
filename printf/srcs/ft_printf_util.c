/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:27:20 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/09 21:32:18 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_putnstr_fd(char	*str, int n, int fd)
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

char	*ft_strjoin_free_s2(char const *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;
	int		i;

	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	if (!(res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	i = -1;
	while (++i < len_s1)
		res[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		res[len_s1 + i] = s2[i];
	res[len_s1 + i] = '\0';
	free(s2);
	return (res);
}

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

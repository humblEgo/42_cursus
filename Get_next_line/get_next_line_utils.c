/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:51:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/02 22:51:22 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return ((void *)tmp);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (dst <= src)
	{
		i = 0;
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		while (--len)
			tmp_dst[len] = tmp_src[len];
		tmp_dst[len] = tmp_src[len];
	}
	return (dst);
}

int		ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		len1;
	int 	len2;
	char	*res;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	res[i] = '\0';
	if (i == n)
		return (res);
	i = -1;
	while (++i < len2 && i < n)
		res[len1 + i] = s2[i];
	res[len1 + i] = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*res;
	int		i;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

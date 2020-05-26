/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 01:08:00 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/28 20:38:16 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp_str;
	char	*res;

	res = NULL;
	tmp_str = (char *)s;
	i = -1;
	while (tmp_str[++i])
		if (tmp_str[i] == c)
			res = &tmp_str[i];
	if (tmp_str[i] == c)
		res = &tmp_str[i];
	return (res);
}

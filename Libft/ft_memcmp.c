/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:21:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/26 00:17:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*tmp_b1;
	unsigned char	*tmp_b2;
	int				res;

	tmp_b1 = (unsigned char *)b1;
	tmp_b2 = (unsigned char *)b2;
	i = 0;
	while (i < len && tmp_b1[i] && tmp_b2[i] && tmp_b1[i] == tmp_b2[i])
		i++;
	res = (int)tmp_b1[i] - (int)tmp_b2[i];
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:12:12 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/28 19:35:41 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_b;

	tmp_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		if (*tmp_b == (unsigned char)c)
			return ((void *)tmp_b);
		tmp_b++;
		i++;
	}
	return (NULL);
}	

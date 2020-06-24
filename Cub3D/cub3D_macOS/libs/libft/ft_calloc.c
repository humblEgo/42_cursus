/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:26:03 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/08 17:16:05 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (!(res = (char *)malloc(nmemb * size)))
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		res[i] = 0;
		i++;
	}
	return ((void *)res);
}

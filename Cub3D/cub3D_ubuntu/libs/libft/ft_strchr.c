/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:58:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/28 20:02:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	i = -1;
	while (tmp[++i])
		if (tmp[i] == c)
			return (&tmp[i]);
	if (tmp[i] == c)
		return (&tmp[i]);
	return (NULL);
}

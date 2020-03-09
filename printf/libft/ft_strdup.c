/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:37:01 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/26 15:59:34 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (s[len])
		len++;
	if (!(dup = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

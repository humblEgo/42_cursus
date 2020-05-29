/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:10:08 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/26 18:19:18 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (res);
}
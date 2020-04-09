/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 01:15:33 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/07 10:48:06 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp_hs;

	tmp_hs = (char *)haystack;
	if (!needle || !needle[0])
		return (tmp_hs);
	i = 0;
	while (i < len && *tmp_hs)
	{
		j = 0;
		while (needle[j] && tmp_hs[j])
		{
			if (needle[j] != tmp_hs[j] || i + j == len)
				break ;
			j++;
		}
		if (needle[j] == '\0')
			return (tmp_hs);
		tmp_hs++;
		i++;
	}
	return (NULL);
}

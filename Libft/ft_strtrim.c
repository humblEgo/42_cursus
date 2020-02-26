/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:20:40 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/26 19:02:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	set_count(char const *s1, char const *set)
{
	int		set_count;
	int		i;

	set_count = 0;
	i = -1;
	while (s1[++i])
		if (is_in_set(s1[i], set))
			set_count++;
	return (set_count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		count;
	int		i;

	count = set_count(s1, set);
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) - count + 1))))
		return (NULL);
	i = 0;
	while (*s1)
	{
		if (is_in_set(*s1, set))
		{
			s1++;
			continue;
		}
		res[i] = *s1;
		i++;
		s1++;
	}
	res[i] = '\0';
	return (res);
}

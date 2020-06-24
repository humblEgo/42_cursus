/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:20:40 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/06 16:21:12 by iwoo             ###   ########.fr       */
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

static int	get_len_trimmed(char const *s1, char const *set)
{
	int		start_idx;
	int		end_idx;

	start_idx = 0;
	while (s1[start_idx] && is_in_set(s1[start_idx], set))
		start_idx++;
	if (ft_strlen(s1) == (size_t)start_idx)
		return (0);
	end_idx = ft_strlen(s1) - 1;
	if (end_idx < 0)
		return (0);
	while (s1[end_idx] && is_in_set(s1[end_idx], set))
		end_idx--;
	return (end_idx - start_idx + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		i;

	if (!(len = get_len_trimmed(s1, set)))
	{
		res = ft_strdup("");
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1 && is_in_set(*s1, set))
		s1++;
	i = 0;
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:02:46 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/26 20:13:12 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*str_malloc_cpy(char const *s, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != c)
		tmp[i] = s[i];
	tmp[i] = '\0';
	return (tmp);
}

void		*free_res(char **res, int i)
{
	int	n;

	n = -1;
	while (++n < i)
		free(res[n]);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	char	**res;

	count = count_words(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(res[i] = str_malloc_cpy(s, c)))
				return (free_res(res, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[count] = NULL;
	return (res);
}

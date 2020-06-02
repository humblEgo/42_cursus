/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 01:07:49 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 04:24:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_count_strings(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	is_num_str(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
	return (TRUE);
}

int	is_correct_num_of_splits(char **split, int correct_num)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	if (count == correct_num)
		return (TRUE);
	return (FALSE);
}

void	free_double_arr(char **arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(arr[i]);
	free(arr);
}

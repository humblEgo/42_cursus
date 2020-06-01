/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 00:57:52 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 01:08:17 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	free_double_arr(char **arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(arr[i]);
	free(arr);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:30:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/27 23:13:21 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"

int	error(int error_type)
{
	if (error_type == ARG_ERROR)
		ft_putstr_fd("Invalid argument", 2);
	else if (error_type == INIT_ERROR)
		ft_putstr_fd("Failed initialize game", 2);
	return (0);
}
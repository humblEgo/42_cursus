/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:30:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/01 00:39:39 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"

int	error(int error_type)
{
	if (error_type == ARG_ERROR)
		ft_putstr_fd("Invalid argument\n", 2);
	else if (error_type == CUB_FILE_ERROR)
		ft_putstr_fd("Not valid cub file\n", 2);
	else if (error_type == CUB_FILE_OPEN_ERROR)
		ft_putstr_fd("Failed to open cub file\n", 2);
	else if (error_type == TEXTURE_FILE_ERROR)
		ft_putstr_fd("Not valid texture file\n", 2);
	else if (error_type == INIT_ERROR)
		ft_putstr_fd("Failed to initialize game\n", 2);
	else if (error_type == SAVE_FILE_ERROR)
		ft_putstr_fd("Failed to save screenshot\n", 2);
	return (0);
}

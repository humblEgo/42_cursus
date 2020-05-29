/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:46:52 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/27 14:12:06 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	open_img(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->window.mlx_ptr, 
				game->texture[i].file, &game->texture[i].width, 
				&game->texture[i].height);
		if (game->texture[i].img == NULL)
			return ;
		game->texture[i].data = (int *)mlx_get_data_addr(game->texture[i].img,
				&game->texture[i].bpp, &game->texture[i].size_line, &game->texture[i].endian);
	}
}
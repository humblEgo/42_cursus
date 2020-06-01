/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:46:52 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/01 20:43:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	open_img(t_game *game)
{
	int	i;

	printf("open_img start\n");
	i = -1;
	while (++i < 5)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->mlx_ptr, 
				game->texture[i].file, &game->texture[i].width, 
				&game->texture[i].height);
		if (game->texture[i].img == NULL)
			return (error(TEXTURE_FILE_ERROR));
		game->texture[i].data = (int *)mlx_get_data_addr(game->texture[i].img,
				&game->texture[i].bpp, &game->texture[i].size_line, &game->texture[i].endian);
	}
	printf("open_img end\n");
	return (TRUE);
}

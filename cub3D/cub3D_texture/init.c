/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:03:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/25 14:42:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	init_game(t_game *game)
{
	game->player.pos_x = 5;
	game->player.pos_y = 6;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.camera_x = 0;
	game->player.move_speed = MOVE_SPEED;
	game->player.rot_speed = ROT_SPEED;
	game->map.width = MAP_WIDTH;
	game->map.height = MAP_HEIGHT;
	game->key_code = -1;
	game->texture[0].file = "./images/redbrick.xpm";
	game->texture[1].file = "./images/bluestone.xpm";
	game->texture[2].file = "./images/wood.xpm";
	game->texture[3].file = "./images/eagle.xpm";
}

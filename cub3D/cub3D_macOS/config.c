/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:35:09 by iwoo              #+#    #+#             */
<<<<<<< HEAD:cub3D/config.c
/*   Updated: 2020/04/02 18:22:48 by iwoo             ###   ########.fr       */
=======
/*   Updated: 2020/05/20 22:51:50 by iwoo             ###   ########.fr       */
>>>>>>> 54bd4be898d4299136a13a7f3361a6e36c1f6423:cub3D/cub3D_macOS/config.c
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	init_player(t_map *map, t_player *player)
{
	player->pos_x = (map->height * map->tile_h) * 0.5;
	player->pos_y = (map->width * map->tile_w) * 0.5;
	player->color = 0xff0000;
	player->pov_angle = M_PI * 0.5;
	player->move_dir = 0;
	player->rotation_dir = 0;
	player->ray_color = 0x005500;
}

void	init_map(t_map *map)
{
	map->height = MAP_HEIGHT;
	map->width = MAP_WIDTH;
	map->tile_h = 32;
	map->tile_w = 32;
	map->color = 0xffffff;
}

void	init_game(t_game *game)
{
	init_map(&game->map);
	init_player(&game->map, &game->player);
	game->key.w_s = 0;
	game->key.a_d = 0;
	game->key.l_r = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:35:09 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/31 23:34:49 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	init_player(t_map *map, t_player *player)
{
	player->pos_x = (map->height * map->tile_h) * 0.5;
	player->pos_y = (map->width * map->tile_w) * 0.5;
	player->color = 0xff0000;
	player->ray.angle = 45;
	player->ray.color = 0x00ff00;
	player->move.x = 0;
	player->move.y = 0;
	player->rotate.r = 0;
	player->rotate.l = 0;
}

void	init_map(t_map *map)
{
	map->height = 9;
	map->width = 10;
	map->tile_h = 32;
	map->tile_w = 32;
	map->color = 0xffffff;
}

void	init_game(t_game *game)
{
	init_map(&game->map);
	init_player(&game->map, &game->player);
}

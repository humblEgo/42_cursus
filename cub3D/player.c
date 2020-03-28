/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/28 22:55:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	init_player(t_map *map, t_player *player)
{
	player->pos_x = (map->height * map->tile_h) * 0.5;
	player->pos_y = (map->width * map->tile_w) * 0.5;
	player->color = 0xff0000;
	player->ray.angle = get_rad(45);
	player->ray.color = 0x00ff00;
}

void	render_ray(t_map *map, t_window *window, t_player *player)
{
	int x;
	int y;

	x = player->pos_x;
	y = player->pos_y;
	while (x < map->width * map->tile_h)
	{
		mlx_pixel_put(window->mlx_ptr,
				window->win_ptr,
				x,
				y,
				player->ray.color);
		x++;
		y = tan(player->ray.angle) * x;
	}
}

void	render_player(t_map *map, t_window *window, t_player *player)
{
	mlx_pixel_put(window->mlx_ptr,
			window->win_ptr,
			player->pos_x, 
			player->pos_y,
			player->color);
	render_ray(map, window, player);
}

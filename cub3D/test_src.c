/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:25:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/25 23:42:10 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "mlx.h"

void	init_map(t_map *map)
{
	map->height = 9;
	map->width = 10;
	map->tile_h = 32;
	map->tile_w = 32;
	map->color = 0xffffff;
}

void	render_tile(int x, int y, t_map *map, t_window *window)
{
	int i;
	int j;

	i = -1;
	while (++i < map->tile_w)
	{
		j = -1;
		while (++j < map->tile_h)
		{
			mlx_pixel_put(window->mlx_ptr, 
					window->win_ptr, 
					x * map->tile_w + i, 
					y *map->tile_h + j, 
					map->color);
		}
	}
}

void	render_map(t_map *map, t_window *window)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->width)
	{
		y = -1;
		while (++y < map->height)
		{
			if (map->map_grid[y][x] == 1)
				render_tile(x, y, map, window);
		}
	}
}

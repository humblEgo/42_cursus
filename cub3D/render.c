/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:42:44 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/31 23:45:32 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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

void	render_ray(t_map *map, t_window *window, t_player *player)
{
	double	x;
	double	y;

	x = player->pos_x;
	y = player->pos_y;
	if ((player->ray.angle >= 0 && player->ray.angle < 90) ||
			(player->ray.angle > 270 && player->ray.angle < 360))
	{
		while (x < map->width * map->tile_w)
		{
			x++;
			y = (player->ray.angle == 0) ? y : y + tan(get_rad(player->ray.angle));
			mlx_pixel_put(window->mlx_ptr,
				window->win_ptr,
				x,
				y,
				player->ray.color);
		}
	}
	else if (player->ray.angle > 90 && player->ray.angle < 270)
	{
		while (x > map->width * map->tile_w * -1)
		{
			x--;
			y = (player->ray.angle == 180) ? y : y - tan(get_rad(player->ray.angle));
			mlx_pixel_put(window->mlx_ptr,
				window->win_ptr,
				x,
				y,
				player->ray.color);
		}
	}
	else
	{
		if (player->ray.angle == 90)
		{
			while (y < map->height * map->tile_h)
			{
				y++;
				mlx_pixel_put(window->mlx_ptr,
					window->win_ptr,
					x,
					y,
					player->ray.color);
			}
		}
		else if (player->ray.angle == 270)
		{
			while (y > map->height * map->tile_h * -1)
			{
				y--;
				mlx_pixel_put(window->mlx_ptr,
					window->win_ptr,
					x,
					y,
					player->ray.color);
			}
		}
	}
}

void	render_player(t_game *game)
{
	mlx_pixel_put(game->window.mlx_ptr,
			game->window.win_ptr,
			game->player.pos_x, 
			game->player.pos_y,
			game->player.color);
//	render_ray(&game->map, &game->window, &game->player);
}

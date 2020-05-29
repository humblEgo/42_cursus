/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:42:44 by iwoo              #+#    #+#             */
<<<<<<< HEAD:cub3D/render.c
/*   Updated: 2020/04/02 18:41:53 by iwoo             ###   ########.fr       */
=======
/*   Updated: 2020/05/20 23:39:02 by iwoo             ###   ########.fr       */
>>>>>>> 54bd4be898d4299136a13a7f3361a6e36c1f6423:cub3D/cub3D_macOS/render.c
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
			if (map->grid[y][x] == 1)
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
	if ((player->pov_angle >= 0 && player->pov_angle < 0.5 * M_PI) ||
			(player->pov_angle > 1.5 * M_PI && player->pov_angle < 2 * M_PI))
	{
		while (x < map->width * map->tile_w)
		{
			x++;
			y = (player->pov_angle == 0) ? y : y + tan(player->pov_angle);
			mlx_pixel_put(window->mlx_ptr,
				window->win_ptr,
				x,
				y,
				player->ray_color);
		}
	}
	else if (player->pov_angle > 0.5 * M_PI && player->pov_angle < 1.5 * M_PI)
	{
		while (x > map->width * map->tile_w * -1)
		{
			x--;
			y = (player->pov_angle == M_PI) ? y : y - tan(player->pov_angle);
			mlx_pixel_put(window->mlx_ptr,
				window->win_ptr,
				x,
				y,
				player->ray_color);
		}
	}
	else
	{
		if (player->pov_angle == 0.5 * M_PI)
		{
			while (y < map->height * map->tile_h)
			{
				y++;
				mlx_pixel_put(window->mlx_ptr,
					window->win_ptr,
					x,
					y,
					player->ray_color);
			}
		}
		else if (player->pov_angle == 1.5 * M_PI)
		{
			while (y > map->height * map->tile_h * -1)
			{
				y--;
				mlx_pixel_put(window->mlx_ptr,
					window->win_ptr,
					x,
					y,
					player->ray_color);
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
	render_ray(&game->map, &game->window, &game->player);
}
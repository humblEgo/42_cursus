/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/30 23:37:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	init_player(t_map *map, t_player *player)
{
	player->pos_x = (map->height * map->tile_h) * 0.5;
	player->pos_y = (map->width * map->tile_w) * 0.5;
	player->color = 0xff0000;
	player->ray.angle = 270;
	player->ray.color = 0x00ff00;
}

void	render_ray(t_map *map, t_window *window, t_player *player)
{
	double	x;
	double	y;
	int		quadrant;

	x = player->pos_x;
	y = player->pos_y;
	quadrant = 0;
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

int		press_key(int	key, t_game *game)
{
	if (key == 'w')
		game->player.pos_y++;
	else if (key == 's')
		game->player.pos_y--;
	else if (key == 'd')
		game->player.pos_x++;
	else if (key == 'a')
		game->player.pos_x--;
	printf("pos_x: %lf\n", game->player.pos_y);
	mlx_pixel_put(game->window.mlx_ptr,
			game->window.win_ptr,
			game->player.pos_x, 
			game->player.pos_y,
			game->player.color);
	render_ray(&game->map, &game->window, &game->player);
}

int		release_key(int	key, t_game *game)
{
	if (key == 'w')
		game->player.pos_y++;
	else if (key == 's')
		game->player.pos_y--;
	else if (key == 'd')
		game->player.pos_x++;
	else if (key == 'a')
		game->player.pos_x--;
	printf("pos_x: %lf\n", game->player.pos_y);
	mlx_pixel_put(game->window.mlx_ptr,
			game->window.win_ptr,
			game->player.pos_x, 
			game->player.pos_y,
			game->player.color);
	render_ray(&game->map, &game->window, &game->player);
}

void	render_player(t_game *game)
{
	mlx_key_hook(game->window.win_ptr, press_key, game); 
//	mlx_key_hook(game->window.win_ptr, release_key, game); 
//	mlx_pixel_put(window->mlx_ptr,
//			window->win_ptr,
//			player->pos_x, 
//			player->pos_y,
//			player->color);
//	render_ray(map, window, player);
}

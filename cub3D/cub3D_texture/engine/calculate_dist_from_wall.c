/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_dist_from_wall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:33:48 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 04:00:08 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	set_camera_raydir_currentpos(t_game *game)
{
	t_render	*rend;
	t_player	*player;

	rend = &game->rend;
	player = &game->player;
	rend->camera_x = (2 * game->x / (double)game->screen_w) - 1;
	rend->ray_dir_x = player->dir_x + player->plane_x * rend->camera_x;
	rend->ray_dir_y = player->dir_y + player->plane_y * rend->camera_x;
	rend->map_x = (int)player->pos_x;
	rend->map_y = (int)player->pos_y;
}

void	set_deltadist_sidedist_step(t_game *game)
{
	t_render	*rend;
	t_player	*player;

	rend = &game->rend;
	player = &game->player;
	if (rend->ray_dir_y == 0)
		rend->delta_dist_x = 0;
	else
		rend->delta_dist_x = (rend->ray_dir_x == 0) ? 1 : fabs(1 / rend->ray_dir_x);
	if (rend->ray_dir_x == 0)
		rend->delta_dist_y = 0;
	else
		rend->delta_dist_y = (rend->ray_dir_y == 0) ? 1 : fabs(1 / rend->ray_dir_y);
	if (rend->ray_dir_x < 0 && (rend->step_x = -1))
		rend->side_dist_x = (player->pos_x - rend->map_x) * rend->delta_dist_x;
	else if (rend->ray_dir_x >= 0 && (rend->step_x = 1))
		rend->side_dist_x = (rend->map_x + 1.0 - player->pos_x) * rend->delta_dist_x;
	if (rend->ray_dir_y < 0 && (rend->step_y = -1))
		rend->side_dist_y = (player->pos_y - rend->map_y) * rend->delta_dist_y;
	else if (rend->ray_dir_y >= 0 && (rend->step_y = 1))
		rend->side_dist_y = (rend->map_y + 1.0 - player->pos_y) * rend->delta_dist_y;
}

void	find_wall_grid(t_game *game)
{
	t_map		*map;
	t_render	*rend;

	map = &game->map;
	rend = &game->rend;
	rend->hit = 0;
	while (rend->hit == 0)
	{
		if (rend->side_dist_x < rend->side_dist_y)
		{
			rend->side_dist_x += rend->delta_dist_x;
			rend->map_x += rend->step_x;
			rend->side = 0;
		}
		else
		{
			rend->side_dist_y += rend->delta_dist_y;
			rend->map_y += rend->step_y;
			rend->side = 1;
		}
		if (map->grid[rend->map_x][rend->map_y] == '1')
			rend->hit = 1;
	}
}

void	set_perp_dist_between_player_and_wall(t_game *game)
{
	t_player	*player;
	t_render	*rend;

	player = &game->player;
	rend = &game->rend;
	if (rend->side == 0)
		rend->perp_wall_dist = (rend->map_x - player->pos_x + (1 - rend->step_x) / 2) / rend->ray_dir_x;
	else
		rend->perp_wall_dist = (rend->map_y - player->pos_y + (1 - rend->step_y) / 2) / rend->ray_dir_y;
	game->zbuffer[game->x] = rend->perp_wall_dist;
}

void	calculate_dist_from_wall(t_game *game)
{
	set_camera_raydir_currentpos(game);
	set_deltadist_sidedist_step(game);
	find_wall_grid(game);
	set_perp_dist_between_player_and_wall(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:33:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/26 16:05:15 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	calculate_ray_position_and_direction(t_player *player, int x)
{
	player->camera_x = (2 * x / (double)SCREEN_WIDTH) - 1;
	player->ray_dir_x = player->dir_x + player->plane_x * player->camera_x;
	player->ray_dir_y = player->dir_y + player->plane_y * player->camera_x;
}

void	set_delta_dist(t_player *player)
{
	double	delta_dist_x;
	double	delta_dist_y;

	if (player->ray_dir_y == 0)
		delta_dist_x = 0;
	else
		delta_dist_x = (player->ray_dir_x == 0) ? 1 : fabs(1 / player->ray_dir_x);
	if (player->ray_dir_x == 0)
		delta_dist_y = 0;
	else
		delta_dist_y = (player->ray_dir_y == 0) ? 1 : fabs(1 / player->ray_dir_y);
	player->delta_dist_x = delta_dist_x;
	player->delta_dist_y = delta_dist_y;
}

void	set_side_dist_and_step(t_player *player)
{
	if (player->ray_dir_x < 0 && (player->step_x = -1))
		player->side_dist_x = (player->pos_x - player->map_x) * player->delta_dist_x;
	else if (player->ray_dir_x >= 0 && (player->step_x = 1))
		player->side_dist_x = (player->map_x + 1.0 - player->pos_x) * player->delta_dist_x;
	if (player->ray_dir_y < 0 && (player->step_y = -1))
		player->side_dist_y = (player->pos_y - player->map_y) * player->delta_dist_y;
	else if (player->ray_dir_y >= 0 && (player->step_y = 1))
		player->side_dist_y = (player->map_y + 1.0 - player->pos_y) * player->delta_dist_y;
}

void	set_map_grid_of_current_pos(t_player *player)
{
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
}

void	find_wall(t_player *player, t_map *map)
{
	player->hit = 0;
	while (player->hit == 0)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (map->grid[player->map_x][player->map_y] == 1)
			player->hit = 1;
	}
}

double	get_perp_wall_dist(double map_n, double pos_n, double step_n, double ray_dir_n)
{
	return ((map_n - pos_n + (1 - step_n) / 2) / ray_dir_n);
}

void	set_perp_dist_between_player_and_wall(t_player *player)
{
	double res;

	if (player->side == 0)
		res = get_perp_wall_dist(player->map_x, player->pos_x, player->step_x, player->ray_dir_x);
	else
		res = get_perp_wall_dist(player->map_y, player->pos_y, player->step_y, player->ray_dir_y);
	player->perp_wall_dist = res;
}


void	calculate_dist_from_wall(t_game *game)
{
	set_map_grid_of_current_pos(&game->player);
	set_delta_dist(&game->player);
	set_side_dist_and_step(&game->player);
	find_wall(&game->player, &game->map);
	set_perp_dist_between_player_and_wall(&game->player);
}


void	fill_vertical_line(t_vertical_line vline, int x, t_img *temp, t_game *game)
{
	int h;
	int	color;
	int	temp_color;

	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	if (game->player.side == 0)
		wall_x = game->player.pos_y + game->player.perp_wall_dist * game->player.ray_dir_y;
	else
		wall_x = game->player.pos_x + game->player.perp_wall_dist * game->player.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)game->texture[3].width);
	if (game->player.side == 0 && game->player.ray_dir_x > 0)
		tex_x = game->texture[3].width - tex_x - 1;
	if (game->player.side == 1 && game->player.ray_dir_y < 0)
		tex_x = game->texture[3].width - tex_x - 1;

	step = 1.0 * (double)game->texture[3].height / (double)vline.height;
	tex_pos = (vline.start - (double)SCREEN_HEIGHT / 2 + (double)vline.height / 2) * step;
	h = -1;
	while (++h + vline.start < vline.end)
	{
		tex_y = (int)tex_pos & (game->texture[0].height - 1);
		tex_pos += step;
		color = game->texture[3].data[(int)(game->texture[3].width * tex_y + tex_x)];
		if (game->player.side == 1)
			temp_color = color / 2;
		else
			temp_color = color;
		temp->data[(vline.start + h) * SCREEN_WIDTH + x] = temp_color;
	}
}

void	fill_wall(t_game *game, int x, t_img *temp)
{
	t_vertical_line	vline;

	vline.height = (int)(SCREEN_HEIGHT / game->player.perp_wall_dist);
	vline.start = (-1 * vline.height / 2) + (SCREEN_HEIGHT / 2);
	if (vline.start < 0)
		vline.start = 0;
	vline.end = (vline.height / 2) + (SCREEN_HEIGHT / 2);
	if (vline.end >= SCREEN_HEIGHT)
		vline.end = SCREEN_HEIGHT - 1;
	fill_vertical_line(vline, x, temp, game);
}

void	render_screen(t_game *game)
{
	t_img	temp;
	int		x;

	temp.img = mlx_new_image(game->window.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	temp.data = (int *)mlx_get_data_addr(temp.img, &temp.bpp, &temp.size_line, &temp.endian);
	x = -1;
	while (++x <= SCREEN_WIDTH)
	{
		calculate_ray_position_and_direction(&game->player, x);
		calculate_dist_from_wall(game);
		fill_wall(game, x, &temp);
	}
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr, temp.img, 0, 0);
	mlx_destroy_image(game->window.mlx_ptr, temp.img);
}

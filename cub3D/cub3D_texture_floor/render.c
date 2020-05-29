/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:33:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/29 13:38:43 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	set_camera_and_ray_dir(t_game *game)
{
	t_render	*rend;
	t_player	*player;

	rend = &game->rend;
	player = &game->player;
	rend->camera_x = (2 * game->x / (double)game->screen_w) - 1;
	rend->ray_dir_x = player->dir_x + player->plane_x * rend->camera_x;
	rend->ray_dir_y = player->dir_y + player->plane_y * rend->camera_x;
}

void	set_delta_dist(t_game *game)
{
	t_render	*rend;

	rend = &game->rend;
	if (rend->ray_dir_y == 0)
		rend->delta_dist_x = 0;
	else
		rend->delta_dist_x = (rend->ray_dir_x == 0) ? 1 : fabs(1 / rend->ray_dir_x);
	if (rend->ray_dir_x == 0)
		rend->delta_dist_y = 0;
	else
		rend->delta_dist_y = (rend->ray_dir_y == 0) ? 1 : fabs(1 / rend->ray_dir_y);
}

void	set_side_dist_and_step(t_game *game)
{
	t_render	*rend;
	t_player	*player;

	rend = &game->rend;
	player = &game->player;
	if (rend->ray_dir_x < 0 && (rend->step_x = -1))
		rend->side_dist_x = (player->pos_x - rend->map_x) * rend->delta_dist_x;
	else if (rend->ray_dir_x >= 0 && (rend->step_x = 1))
		rend->side_dist_x = (rend->map_x + 1.0 - player->pos_x) * rend->delta_dist_x;
	if (rend->ray_dir_y < 0 && (rend->step_y = -1))
		rend->side_dist_y = (player->pos_y - rend->map_y) * rend->delta_dist_y;
	else if (rend->ray_dir_y >= 0 && (rend->step_y = 1))
		rend->side_dist_y = (rend->map_y + 1.0 - player->pos_y) * rend->delta_dist_y;
}

void	set_map_grid_of_current_pos(t_game *game)
{
	t_player	*player;
	t_render	*rend;

	player = &game->player;
	rend = &game->rend;
	rend->map_x = (int)player->pos_x;
	rend->map_y = (int)player->pos_y;
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
		if (map->temp[rend->map_x][rend->map_y] > 0)
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
}


void	calculate_dist_from_wall(t_game *game)
{
	set_camera_and_ray_dir(game);
	set_map_grid_of_current_pos(game);
	set_delta_dist(game);
	set_side_dist_and_step(game);
	find_wall_grid(game);
	set_perp_dist_between_player_and_wall(game);
}

void	init_wall_info(t_game *game, t_img wall_texture, t_line draw_line)
{
	t_player	*player;
	t_render	*rend;

	player = &game->player;
	rend = &game->rend;
	if (rend->side == 0)
		rend->wall_x = player->pos_y + rend->perp_wall_dist * rend->ray_dir_y;
	else
		rend->wall_x = player->pos_x + rend->perp_wall_dist * rend->ray_dir_x;
	rend->wall_x -= floor(rend->wall_x);
	rend->tex_x = (int)(rend->wall_x * (double)wall_texture.width);
	if (rend->side == 0 && rend->ray_dir_x > 0)
		rend->tex_x = wall_texture.width - rend->tex_x - 1;
	if (rend->side == 1 && rend->ray_dir_y < 0)
		rend->tex_x = wall_texture.width - rend->tex_x - 1;
	rend->step = 1.0 * (double)wall_texture.height / (double)draw_line.height;
	rend->tex_pos = (double)(draw_line.start - game->screen_h / 2 + draw_line.height / 2) * rend->step;
}


void	fill_vertical_line(t_game *game, t_img *screen, t_line draw_line, t_img wall_texture)
{
	int y;
	int	color;
	t_render	*rend;
	
	rend = &game->rend;
	init_wall_info(game, wall_texture, draw_line);
	y = -1;
	while (++y < game->screen_h)
	{
		if (y < draw_line.start)
			screen->data[y * game->screen_w + game->x] = game->color.ceiling;
		else if (y < draw_line.end)
		{
			rend->tex_y = (int)rend->tex_pos & (wall_texture.height - 1);
			rend->tex_pos += rend->step;
			color = wall_texture.data[(int)(wall_texture.width * rend->tex_y + rend->tex_x)];
			screen->data[y * game->screen_w + game->x] = color;
		}
		else
			screen->data[y * game->screen_w + game->x] = game->color.floor;
	}

//	/* floor and ceiling */
//	if (rend->side == 0 && rend->ray_dir_x > 0)
//	{
//		floor_x_wall = rend->map_x;
//		floor_y_wall = rend->map_y + rend->wall_x;
//	}
//	else if (rend->side == 0 && rend->ray_dir_x < 0)
//	{
//		floor_x_wall = rend->map_x + 1.0;
//		floor_y_wall = rend->map_y + rend->wall_x;
//	}
//	else if (rend->side == 0 && rend->ray_dir_x < 0)
//	{
//		floor_x_wall = rend->map_x + rend->wall_x;
//		floor_y_wall = rend->map_y;
//	}
//	else
//	{
//		floor_x_wall = rend->map_x + rend->wall_x;
//		floor_y_wall = rend->map_y + 1.0;
//	}
//	dist_wall = rend->perp_wall_dist;
//
//	/* floor and ceiling*/
//
//	int z;
//	z = draw_line.start;
//	dist_player = 0.0;
//	while (++y < game->screen_h)
//	{
//		current_dist = game->screen_h / (2.0 * y - game->screen_h);
//		weight = (current_dist - dist_player) / (dist_wall - dist_player);
//		current_floor_x = weight * floor_x_wall + (1.0 - weight) * player->pos_x; 
//		current_floor_y = weight * floor_y_wall + (1.0 - weight) * player->pos_y; 
//		floor_tex_x = (int)(current_floor_x * game->texture[1].width) % game->texture[1].width;
//		floor_tex_y = (int)(current_floor_y * game->texture[1].height) % game->texture[1].height;
//		screen_color = game->texture[1].data[(int)(game->texture[1].width * floor_tex_y + floor_tex_x)];
//		screen->data[y * game->screen_w + game->x] = screen_color;
//		screen_color = game->texture[2].data[(int)(game->texture[2].width * floor_tex_y + floor_tex_x)];
//		screen->data[z * game->screen_w + game->x] = screen_color;
//		z--;
//	}
}

t_line	get_draw_line(t_game *game)
{
	t_line	draw_line;

	draw_line.height = (int)(game->screen_h / game->rend.perp_wall_dist);
	draw_line.start = (-1 * draw_line.height / 2) + (game->screen_h / 2);
	if (draw_line.start < 0)
		draw_line.start = 0;
	draw_line.end = (draw_line.height / 2) + (game->screen_h / 2);
	if (draw_line.end >= game->screen_h)
		draw_line.end = game->screen_h - 1;
	return (draw_line);
}

t_img	get_wall_texture(t_game *game)
{
	t_render	*rend;
	t_img		texture;

	rend = &game->rend;
	if (rend->side == 1)
	{
		if ((rend->ray_dir_x <= 0 && rend->ray_dir_y <= 0) ||
				(rend->ray_dir_x >= 0 && rend->ray_dir_y <= 0))
			texture = game->texture[0];
		else
			texture = game->texture[1];
	}
	else
	{
		if ((rend->ray_dir_x <= 0 && rend->ray_dir_y <= 0) ||
				(rend->ray_dir_x <= 0 && rend->ray_dir_y >= 0))
			texture = game->texture[2];
		else
			texture = game->texture[3];
	}
	return (texture);
}


void	fill_map_image(t_game *game, t_img *screen)
{
	t_line	draw_line;
	t_img	wall_texture;

	draw_line = get_draw_line(game);
	wall_texture = get_wall_texture(game);
	fill_vertical_line(game, screen, draw_line, wall_texture);
}

void	render_screen(t_game *game)
{
	t_img	screen;

	screen.img = mlx_new_image(game->mlx_ptr, game->screen_w, game->screen_h);
	screen.data = (int *)mlx_get_data_addr(screen.img, &screen.bpp, &screen.size_line, &screen.endian);
	game->x = -1;
	while (++game->x <= game->screen_w)
	{
		calculate_dist_from_wall(game);
		fill_map_image(game, &screen);
//		game->zbuffer[game->x] = rend->perp_wall_dist;
	}
	//fill_item(game);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, screen.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, screen.img);



}

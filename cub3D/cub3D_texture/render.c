/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:33:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/01 20:56:04 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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

void	set_floor_wall(t_game *game)
{
	t_render	*rend;

	rend = &game->rend;
	if (rend->side == 0 && rend->ray_dir_x > 0)
	{
		rend->floor_x_wall = rend->map_x;
		rend->floor_y_wall = rend->map_y + rend->wall_x;
	}
	else if (rend->side == 0 && rend->ray_dir_x < 0)
	{
		rend->floor_x_wall = rend->map_x + 1.0;
		rend->floor_y_wall = rend->map_y + rend->wall_x;
	}
	else if (rend->side == 0 && rend->ray_dir_x < 0)
	{
		rend->floor_x_wall = rend->map_x + rend->wall_x;
		rend->floor_y_wall = rend->map_y;
	}
	else
	{
		rend->floor_x_wall = rend->map_x + rend->wall_x;
		rend->floor_y_wall = rend->map_y + 1.0;
	}
}

void	cast_floor_and_ceiling(t_game *game, t_img *screen, t_line draw_line)
{
	t_render	*rend;
	t_player	*player;
	int			floor_y;
	int			ceiling_y;
	int			color;

	rend = &game->rend;
	player = &game->player;
	set_floor_wall(game);
	rend->dist_wall = rend->perp_wall_dist;

	/* floor and ceiling*/
	ceiling_y = draw_line.start;
	rend->dist_player = 0.0;
	floor_y = draw_line.end;
	while (++floor_y < game->screen_h)
	{
		rend->current_dist = game->screen_h / (2.0 * floor_y - game->screen_h);
		rend->weight = (rend->current_dist - rend->dist_player) / (rend->dist_wall - rend->dist_player);
		rend->current_floor_x = rend->weight * rend->floor_x_wall + (1.0 - rend->weight) * player->pos_x; 
		rend->current_floor_y = rend->weight * rend->floor_y_wall + (1.0 - rend->weight) * player->pos_y; 
		rend->floor_tex_x = (int)(rend->current_floor_x * game->texture[1].width) % game->texture[1].width;
		rend->floor_tex_y = (int)(rend->current_floor_y * game->texture[1].height) % game->texture[1].height;
		color = game->texture[1].data[(int)(game->texture[1].width * rend->floor_tex_y + rend->floor_tex_x)];
		screen->data[floor_y * game->screen_w + game->x] = color;
		color = game->texture[2].data[(int)(game->texture[2].width * rend->floor_tex_y + rend->floor_tex_x)];
		screen->data[ceiling_y * game->screen_w + game->x] = color;
		ceiling_y--;
	}
}

void	fill_vertical_line(t_game *game, t_img *screen, t_line draw_line, t_img wall_texture)
{
	int			y;
	int			color;
	t_render	*rend;
	
	rend = &game->rend;
	init_wall_info(game, wall_texture, draw_line);
	y = -1;
	while (++y < game->screen_h)
	{
		if (y < draw_line.start && (game->floor_ceiling_texture == FALSE))
			screen->data[y * game->screen_w + game->x] = game->color.ceiling;
		else if (y >= draw_line.start && y <= draw_line.end)
		{
			rend->tex_y = (int)rend->tex_pos & (wall_texture.height - 1);
			rend->tex_pos += rend->step;
			color = wall_texture.data[(int)(wall_texture.width * rend->tex_y + rend->tex_x)];
			screen->data[y * game->screen_w + game->x] = color;
		}
		else if (y < game->screen_h && (game->floor_ceiling_texture == FALSE))
			screen->data[y * game->screen_w + game->x] = game->color.floor;
	}
	if (game->floor_ceiling_texture == TRUE)
		cast_floor_and_ceiling(game, screen, draw_line);
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
	while (++game->x < game->screen_w)
	{
		calculate_dist_from_wall(game);
		fill_map_image(game, &screen);
	}
	fill_item_image(game, &screen);
	if (game->save_option == TRUE)
		save_bmp(game, &screen);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, screen.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, screen.img);


}

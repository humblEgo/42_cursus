/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:33:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 04:35:26 by iwoo             ###   ########.fr       */
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

void	fill_map_image(t_game *game, t_img *screen, t_line draw_line, t_img wall_texture)
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
		fill_texture_to_floor_ceiling(game, screen, draw_line);
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

void	raycast_screen(t_game *game)
{
	t_img	screen;
	t_line	draw_line;
	t_img	wall_texture;

	screen.img = mlx_new_image(game->mlx_ptr, game->screen_w, game->screen_h);
	screen.data = (int *)mlx_get_data_addr(screen.img, &screen.bpp, &screen.size_line, &screen.endian);
	game->x = -1;
	while (++game->x < game->screen_w)
	{
		calculate_dist_from_wall(game);
		draw_line = get_draw_line(game);
		wall_texture = get_wall_texture(game);
		fill_map_image(game, &screen, draw_line, wall_texture);
	}
	fill_item_image(game, &screen);
	if (game->save_option == TRUE)
		save_bmp(game, &screen);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, screen.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, screen.img);
}

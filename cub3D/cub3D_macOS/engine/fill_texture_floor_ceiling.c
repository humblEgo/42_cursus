/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_floor_ceiling.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:33:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 14:57:49 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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

void	calculate_rend(t_game *game, int floor_y)
{
	t_player	*player;
	t_render	*rd;

	player = &game->player;
	rd = &game->rend;
	rd->current_dist = game->screen_h / (2.0 * floor_y - game->screen_h);
	rd->weight = rd->current_dist / rd->perp_wall_dist;
	rd->current_floor_x = rd->weight * rd->floor_x_wall
		+ (1.0 - rd->weight) * player->pos_x;
	rd->current_floor_y = rd->weight * rd->floor_y_wall
		+ (1.0 - rd->weight) * player->pos_y;
}

void	fill_floor_color(t_game *game, int floor_y, t_img *screen)
{
	t_render	*rd;
	int			color;

	rd = &game->rend;
	rd->floor_tex_x = (int)(rd->current_floor_x
			* game->texture[5].width) % game->texture[5].width;
	rd->floor_tex_y = (int)(rd->current_floor_y
			* game->texture[5].height) % game->texture[5].height;
	color = game->texture[5].data[(int)(game->texture[5].width
			* rd->floor_tex_y + rd->floor_tex_x)];
	screen->data[floor_y * game->screen_w + game->x] = color;
}

void	fill_ceiling_color(t_game *game, int ceiling_y, t_img *screen)
{
	t_render	*rd;
	int			color;

	rd = &game->rend;
	rd->floor_tex_x = (int)(rd->current_floor_x
			* game->texture[6].width) % game->texture[6].width;
	rd->floor_tex_y = (int)(rd->current_floor_y
			* game->texture[6].height) % game->texture[6].height;
	color = game->texture[6].data[(int)(game->texture[6].width
			* rd->floor_tex_y + rd->floor_tex_x)];
	screen->data[ceiling_y * game->screen_w + game->x] = color;
}

void	fill_texture_floor_ceiling(t_game *game, t_img *scrn, t_line draw_line)
{
	int			floor_y;
	int			ceiling_y;

	set_floor_wall(game);
	ceiling_y = draw_line.start;
	floor_y = draw_line.end + 1;
	while (floor_y < game->screen_h)
	{
		calculate_rend(game, floor_y);
		fill_floor_color(game, floor_y, scrn);
		fill_ceiling_color(game, ceiling_y, scrn);
		floor_y++;
		ceiling_y--;
	}
}

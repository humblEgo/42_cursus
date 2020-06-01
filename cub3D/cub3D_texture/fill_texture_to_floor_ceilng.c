/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_to_floor_ceilng.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:33:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 04:33:32 by iwoo             ###   ########.fr       */
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

void	fill_texture_to_floor_ceiling(t_game *game, t_img *screen, t_line draw_line)
{
	t_render	*rend;
	t_player	*player;
	int			floor_y;
	int			ceiling_y;
	int			color;

	rend = &game->rend;
	player = &game->player;
	set_floor_wall(game);
	ceiling_y = draw_line.start;
	floor_y = draw_line.end;
	while (++floor_y < game->screen_h)
	{
		rend->current_dist = game->screen_h / (2.0 * floor_y - game->screen_h);
		rend->weight = rend->current_dist / rend->perp_wall_dist;
		rend->current_floor_x = rend->weight * rend->floor_x_wall + (1.0 - rend->weight) * player->pos_x; 
		rend->current_floor_y = rend->weight * rend->floor_y_wall + (1.0 - rend->weight) * player->pos_y; 
		rend->floor_tex_x = (int)(rend->current_floor_x * game->texture[5].width) % game->texture[5].width;
		rend->floor_tex_y = (int)(rend->current_floor_y * game->texture[5].height) % game->texture[5].height;
		color = game->texture[5].data[(int)(game->texture[5].width * rend->floor_tex_y + rend->floor_tex_x)];
		screen->data[floor_y * game->screen_w + game->x] = color;
		rend->floor_tex_x = (int)(rend->current_floor_x * game->texture[6].width) % game->texture[6].width;
		rend->floor_tex_y = (int)(rend->current_floor_y * game->texture[6].height) % game->texture[6].height;
		color = game->texture[6].data[(int)(game->texture[6].width * rend->floor_tex_y + rend->floor_tex_x)];
		screen->data[ceiling_y * game->screen_w + game->x] = color;
		ceiling_y--;
	}
}

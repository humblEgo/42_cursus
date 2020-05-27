/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 01:36:55 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/27 15:24:04 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NUMBER_SPRITES 3
#define TEX_WIDTH 64
#include "ft_cub3d.h"

void	fill_item(t_game *game)
{
	t_sprite	sprite[NUMBER_SPRITES];
	int			sprite_order[NUMBER_SPRITES];
	double		sprite_dist[NUMBER_SPRITES];
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;

	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			sprite_width;

	int			i;
	int			stripe;
	int			tex_x;

	sprite[0] = {2.0, 6.0, 4};
	sprite[1] = {5.0, 7.0, 4};
	sprite[2] = {8.0, 8.0, 4};

	i = -1;
	while (++i < NUMBER_SPRITES)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((game->player.pos_x - sprite[i].x) * (game->player.pos_x - sprite[i].x) + (game->player.pos_y - sprite[i].y) * (game->player.pos_y - sprite[i].y));
	}

	sort_sprites(sprite_order, sprite_dist, NUMBER_SPRITES);

	i = -1;
	while (++i < NUMBER_SPRITES)
	{
		sprite_x = sprite[sprite_order[i]].x - game->player.pos_x;
		sprite_y = sprite[sprite_order[i]].y - game->player.pos_y;
		inv_det = 1.0 / (game->player.plane_x * game->player.dir_y - game->player.dir_x * game->plane_y);
		transform_x = inv_det * (game->player.dir_y * sprite_x - game->player.dir_x * sprite_y);
		transform_y = inv_det * (-game->player.plane_y * sprite_x + game->player.plane_x * sprite_y);
		sprite_screen_x = (int)((SCREEN_WIDTH / 2) * (1 + transform_x / transform_y));
		sprite_height = abs((int)(SCREEN_HEIGHT / transform_y));
		draw_start_y = -sprite_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = sprite_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end_y >= SCREEN_HEIGHT)
			draw_end_y = SCREEN_HEIGHT - 1;

		sprite_width = abs((int)(SCREEN_HEIGHT / transform_y));
		draw_start_x = -sprite_width / 2 + sprite_screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = sprite_width / 2 + sprite_screen_x;
		if (draw_end_x >= SCREEN_HEIGHT)
			draw_end_x = SCREEN_WIDTH - 1;

		stripe = draw_start_x;
		while (stripe < draw_end_x)
		{
			tex_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * TEX_WIDTH / sprite_width) / 256;
			if (transform_y > 0 && stripe > 0 && stripe < SCREEN_WIDTH && transform_y < zbuffer[stripe])
			{
				int	y = draw_start_y;
				while (y < draw_end_y)
				{
					int d = (y) * 256 - SCREEN_HEIGHT * 128 + sprite_height * 128;
					int	tex_y = ((d * TEX_HEIGHT) / sprite_height) / 256;
					int color = game->texture[sprite[sprite_order[i]].texture][TEX_WIDTH * tex_y + tex_x];
				}
			}

			stripe++;
		}


	}
		
	

	
}

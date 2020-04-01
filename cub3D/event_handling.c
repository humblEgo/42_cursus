/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/01 16:04:45 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		press_key(int key, t_game *game)
{
	game->key_code = key;
	if (key == KEY_W)
		game->player.move_dir = 1;
	else if (key == KEY_S)
		game->player.move_dir = -1;
	else if (key == KEY_D)
		game->player.move_dir = 1;
	else if (key == KEY_A)
		game->player.move_dir = -1;
	else if (key == KEY_RIGHT)
		game->player.rotation_dir = 1;
	else if (key == KEY_LEFT)
		game->player.rotation_dir = -1;
	game->moved = TRUE;
	return (0);
}

void	update_player(t_game *game)
{
	double	move_dist;

	move_dist = game->player.move_dir * MOVE_SPEED;
	if (game->key_code == KEY_W || game->key_code == KEY_S)
	{
		game->player.pos_x += cos(game->player.pov_angle) * move_dist;
		game->player.pos_y += sin(game->player.pov_angle) * move_dist;
	}
	else if (game->key_code == KEY_D || game->key_code == KEY_A)
	{
		game->player.pos_x += -sin(game->player.pov_angle) * move_dist;
		game->player.pos_y += cos(game->player.pov_angle) * move_dist;
	}
	if (game->key_code == KEY_RIGHT || game->key_code == KEY_LEFT)
	{
		game->player.pov_angle += get_rad(game->player.rotation_dir * ROT_SPEED);
		if (game->player.pov_angle >= 2 * M_PI)
			game->player.pov_angle = 0;
		else if (game->player.pov_angle <= 0)
			game->player.pov_angle = 2 * M_PI;
	}
}

int		release_key(int	key, t_game *game)
{
	printf("%d\n", key);
	/*if (key == 'w')
		game->player.pos_y++;
	else if (key == 's')
		game->player.pos_y--;
	else if (key == 'd')
		game->player.pos_x++;
	else if (key == 'a')
		game->player.pos_x--; */
	return (0);
}

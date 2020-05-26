/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/02 18:51:46 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		press_key(int key, t_game *game)
{
	if (key == KEY_W)
	{
		game->player.move_dir = 1;
		game->key.w_s = key;
	}
	else if (key == KEY_S)
	{
		game->player.move_dir = -1;
		game->key.w_s = key;
	}
	if (key == KEY_D)
	{
		game->player.move_dir = 1;
		game->key.a_d = key;
	}
	else if (key == KEY_A)
	{
		game->player.move_dir = -1;
		game->key.a_d = key;
	}
	if (key == KEY_RIGHT)
	{
		game->player.rotation_dir = 1;
		game->key.l_r = key;
	}
	else if (key == KEY_LEFT)
	{
		game->player.rotation_dir = -1;
		game->key.l_r = key;
	}
	game->moved = TRUE;
	return (0);
}

int		release_key(int	key, t_game *game)
{
	if (key == KEY_W)
	{
		game->player.move_dir = 0;
		game->key.w_s = 0;
	}
	else if (key == KEY_S)
	{
		game->player.move_dir = 0;
		game->key.w_s = 0;
	}
	if (key == KEY_D)
	{
		game->player.move_dir = 0;
		game->key.a_d = 0;
	}
	else if (key == KEY_A)
	{
		game->player.move_dir = 0;
		game->key.a_d = 0;
	}
	if (key == KEY_RIGHT)
	{
		game->player.rotation_dir = 0;
		game->key.l_r = 0;
	}
	else if (key == KEY_LEFT)
	{
		game->player.rotation_dir = 0;
		game->key.l_r = 0;
	}
	return (0);
}

void	update_player(t_game *game)
{
	double	move_dist;

	move_dist = game->player.move_dir * MOVE_SPEED;
	if (game->key.w_s == KEY_W || game->key.w_s == KEY_S)
	{
		game->player.pos_x += cos(game->player.pov_angle) * move_dist;
		game->player.pos_y += sin(game->player.pov_angle) * move_dist;
	}
	if (game->key.a_d == KEY_D || game->key.a_d == KEY_A)
	{
		game->player.pos_x += -sin(game->player.pov_angle) * move_dist;
		game->player.pos_y += cos(game->player.pov_angle) * move_dist;
	}
	if (game->key.l_r == KEY_RIGHT || game->key.l_r == KEY_LEFT)
	{
		game->player.pov_angle += get_rad(game->player.rotation_dir * ROT_SPEED);
		if (game->player.pov_angle >= 2 * M_PI)
			game->player.pov_angle = 0;
		else if (game->player.pov_angle <= 0)
			game->player.pov_angle = 2 * M_PI;
	}
}



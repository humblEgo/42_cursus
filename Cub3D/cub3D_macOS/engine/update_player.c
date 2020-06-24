/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 14:40:04 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		is_wall(t_game *game, int new_map_x, int new_map_y)
{
	t_map		*map;
	t_player	*player;

	map = &game->map;
	player = &game->player;
	if (map->grid[(int)player->pos_x][new_map_y] != '0' &&
			map->grid[new_map_x][(int)player->pos_y] != '0')
		return (TRUE);
	if (map->grid[new_map_x][new_map_y] != '0')
		return (TRUE);
	return (FALSE);
}

void	move_forward_or_backward(t_game *game)
{
	t_player	*player;
	double		move_dir_x;
	double		move_dir_y;

	player = &game->player;
	if (game->key_code == KEY_W)
	{
		move_dir_x = player->dir_x * player->move_speed;
		move_dir_y = player->dir_y * player->move_speed;
	}
	else
	{
		move_dir_x = (-1) * player->dir_x * player->move_speed;
		move_dir_y = (-1) * player->dir_y * player->move_speed;
	}
	if (is_wall(game, (int)(player->pos_x + move_dir_x),
				(int)(player->pos_y + move_dir_y)))
		return ;
	player->pos_x += move_dir_x;
	player->pos_y += move_dir_y;
}

void	move_rightward_or_leftward(t_game *game)
{
	double		move_dir_x;
	double		move_dir_y;
	t_player	*player;

	player = &game->player;
	if (game->key_code == KEY_D)
	{
		move_dir_x = player->dir_y * player->move_speed;
		move_dir_y = (-1) * player->dir_x * player->move_speed;
	}
	else
	{
		move_dir_x = (-1) * player->dir_y * player->move_speed;
		move_dir_y = player->dir_x * player->move_speed;
	}
	if (is_wall(game, (int)(player->pos_x + move_dir_x),
				(int)(player->pos_y + move_dir_y)))
		return ;
	player->pos_x += move_dir_x;
	player->pos_y += move_dir_y;
}

void	turn_pov(t_game *game)
{
	double		tmp_dir_x;
	double		tmp_p_x;
	double		rot_speed;
	t_player	*player;

	player = &game->player;
	tmp_dir_x = player->dir_x;
	tmp_p_x = player->plane_x;
	if (game->key_code == KEY_RIGHT)
		rot_speed = -player->rot_speed;
	else
		rot_speed = player->rot_speed;
	player->dir_x = tmp_dir_x * cos(rot_speed) - player->dir_y * sin(rot_speed);
	player->dir_y = tmp_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	player->plane_x = tmp_p_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = tmp_p_x * sin(rot_speed)
		+ player->plane_y * cos(rot_speed);
}

void	update_player(t_game *game)
{
	if (game->key_code == KEY_W || game->key_code == KEY_S)
		move_forward_or_backward(game);
	if (game->key_code == KEY_D || game->key_code == KEY_A)
		move_rightward_or_leftward(game);
	if (game->key_code == KEY_RIGHT || game->key_code == KEY_LEFT)
		turn_pov(game);
	game->key_code = -1;
}

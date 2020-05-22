/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/22 22:45:41 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		press_key(int key, t_game *game)
{
	printf("key: %d\n", key);
	game->key_code = key;
	if (key == KEY_W)
	{
		game->player.dir_x *= 1.0;
		game->player.dir_y *= 1.0;
	}
	else if (key == KEY_S)
	{
		game->player.dir_x *= -1.0;
		game->player.dir_y *= -1.0;
	}
	else if (key == KEY_D)
		game->player.dir_x = 1.0;
	else if (key == KEY_A)
		game->player.dir_y = -1.0;
	else if (key == KEY_RIGHT)
		game->player.rot_speed *= 1;
	else if (key == KEY_LEFT)
		game->player.rot_speed *= -1;
	game->moved = TRUE;
	return (0);
}

int		is_wall(t_game *game, int x, int y)
{
	if (game->map.grid[x][y] != 0)
		return (TRUE);
	return (FALSE);
}

void	update_player(t_game *game)
{
	int		new_map_x;
	int		new_map_y;
	double	temp_dir_x;
	double	temp_plane_x;

	if (game->key_code == KEY_W || game->key_code == KEY_S)
	{
		new_map_x = (int)(game->player.pos_x + 
				game->player.dir_x * game->player.move_speed);
		new_map_y = (int)(game->player.pos_y + 
				game->player.dir_y * game->player.move_speed);
		if (is_wall(game, new_map_x, new_map_y))
			return ;
		game->player.pos_x += game->player.dir_x * game->player.move_speed;
		game->player.pos_y += game->player.dir_y * game->player.move_speed;
	}
	else if (game->key_code == KEY_D || game->key_code == KEY_A)
	{
		return ;
	}
	if (game->key_code == KEY_RIGHT || game->key_code == KEY_LEFT)
	{
		temp_dir_x = game->player.dir_x;
		game->player.dir_x = temp_dir_x * cos(game->player.rot_speed) -
			game->player.dir_y * sin(game->player.rot_speed);
		game->player.dir_y = temp_dir_x * sin(game->player.rot_speed) +
			game->player.dir_y * cos(game->player.rot_speed);
		temp_plane_x = game->player.plane_x;
		game->player.plane_x = temp_plane_x * cos(game->player.rot_speed) -
			game->player.plane_y * sin(game->player.rot_speed);
		game->player.plane_y = temp_plane_x * sin(game->player.rot_speed) +
			game->player.plane_y * cos(game->player.rot_speed);
		return ;
	}
}
/*
int		release_key(int	key, t_game *game)
{
	printf("%d\n", key);
	if (key == 'w')
		game->player.pos_y++;
	else if (key == 's')
		game->player.pos_y--;
	else if (key == 'd')
		game->player.pos_x++;
	else if (key == 'a')
		game->player.pos_x--; 
	return (0);
}*/

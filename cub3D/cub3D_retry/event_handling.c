/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/23 23:32:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		press_key(int key, t_game *game)
{
	printf("pressed key: %d\n", key);
	if (key == KEY_W || key == KEY_S)
		game->key_code[0] = key;
	else if (key == KEY_D || key == KEY_A)
		game->key_code[1] = key;
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		game->key_code[2] = key;
	game->moved = TRUE;
	return (0);
}

int		release_key(int key, t_game *game)
{
	printf("released key: %d\n", key);
	if (key == KEY_W || key == KEY_S)
		game->key_code[0] = -1;
	else if (key == KEY_D || key == KEY_A)
		game->key_code[1] = -1;
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		game->key_code[2] = -1;
	game->moved = TRUE;
	return (0);
}


int		is_wall(t_map *map, int x, int y)
{
	if (map->grid[x][y] != 0)
		return (TRUE);
	return (FALSE);
}

void	move_forward(t_player *player, t_map *map)
{
	printf("move_forward\n");
	int	new_map_x;
	int	new_map_y;
	
	new_map_x = (int)(player->pos_x + 
			player->dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y + 
			player->dir_y * player->move_speed);
	if (is_wall(map, new_map_x, new_map_y))
		return ;
	player->pos_x += player->dir_x * player->move_speed;
	player->pos_y += player->dir_y * player->move_speed;
}

void	move_backward(t_player *player, t_map *map)
{
	int	new_map_x;
	int	new_map_y;
	
	printf("move_backward\n");
	new_map_x = (int)(player->pos_x - 
			player->dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y - 
			player->dir_y * player->move_speed);
	if (is_wall(map, new_map_x, new_map_y))
		return ;
	player->pos_x -= player->dir_x * player->move_speed;
	player->pos_y -= player->dir_y * player->move_speed;
}

void	move_rightward(t_player *player, t_map *map)
{
	printf("move_rightward\n");
	int		new_map_x;
	int		new_map_y;
	double	temp_dir_x;
	double	temp_dir_y;

	temp_dir_x = player->dir_y; 
	temp_dir_y = player->dir_x; 
	new_map_x = (int)(player->pos_x + temp_dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y - temp_dir_y * player->move_speed);
	if (is_wall(map, new_map_x, new_map_y))
		return ;
	player->pos_x += temp_dir_x * player->move_speed;
	player->pos_y -= temp_dir_y * player->move_speed;
}

void	move_leftward(t_player *player, t_map *map)
{
	printf("move_leftward\n");
	int		new_map_x;
	int		new_map_y;
	double	temp_dir_x;
	double	temp_dir_y;

	temp_dir_x = player->dir_y; 
	temp_dir_y = player->dir_x; 
	new_map_x = (int)(player->pos_x - temp_dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y + temp_dir_y * player->move_speed);
	if (is_wall(map, new_map_x, new_map_y))
		return ;
	player->pos_x -= temp_dir_x * player->move_speed;
	player->pos_y += temp_dir_y * player->move_speed;
}


void	turn_right(t_player *player)
{
	double	temp_dir_x;
	double	temp_plane_x;
	double	rot_speed;

	printf("turn_right\n");
	temp_dir_x = player->dir_x;
	rot_speed = player->rot_speed;
	player->dir_x = temp_dir_x * cos(-rot_speed) -
		player->dir_y * sin(-rot_speed);
	player->dir_y = temp_dir_x * sin(-rot_speed) +
		player->dir_y * cos(-rot_speed);
	temp_plane_x = player->plane_x;
	player->plane_x = temp_plane_x * cos(-rot_speed) -
		player->plane_y * sin(-rot_speed);
	player->plane_y = temp_plane_x * sin(-rot_speed) +
		player->plane_y * cos(-rot_speed);
}

void	turn_left(t_player *player)
{
	double	temp_dir_x;
	double	temp_plane_x;
	double	rot_speed;

	printf("turn_left\n");
	temp_dir_x = player->dir_x;
	rot_speed = player->rot_speed;
	player->dir_x = temp_dir_x * cos(rot_speed) -
		player->dir_y * sin(rot_speed);
	player->dir_y = temp_dir_x * sin(rot_speed) +
		player->dir_y * cos(rot_speed);
	temp_plane_x = player->plane_x;
	player->plane_x = temp_plane_x * cos(rot_speed) -
		player->plane_y * sin(rot_speed);
	player->plane_y = temp_plane_x * sin(rot_speed) +
		player->plane_y * cos(rot_speed);
}

void	init_key_code(t_game *game)
{
	printf("init!\n");
	game->key_code[0] = -1;
	game->key_code[1] = -1;
	game->key_code[2] = -1;
}

void	update_player(t_game *game)
{
	t_player 	*player;
	t_map		*map;

	player = &game->player;
	map	= &game->map;
	if (game->key_code[0] == KEY_W)
		move_forward(player, map);
	else if (game->key_code[0] == KEY_S)
		move_backward(player, map);
	if (game->key_code[1] == KEY_D)
		move_rightward(player, map);
	else if (game->key_code[1] == KEY_A)
		move_leftward(player, map);
	if (game->key_code[2] == KEY_RIGHT)
		turn_right(player);
	else if (game->key_code[2] == KEY_LEFT)
		turn_left(player);
	init_key_code(game);
}

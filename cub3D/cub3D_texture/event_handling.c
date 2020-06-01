/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/01 16:30:12 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		exit_game(t_game *game)
{
	printf("exit\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	return (0);
}

int		press_key(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == KEY_W || key == KEY_S)
		game->key_code = key;
	else if (key == KEY_D || key == KEY_A)
		game->key_code = key;
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		game->key_code = key;
	else if (key == KEY_ESC)
		exit_game(game);
	game->moved = TRUE;
	return (0);
}

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

void	move_forward(t_game *game)
{
	t_player	*player;
	int			new_map_x;
	int			new_map_y;
	
	player = &game->player;
	new_map_x = (int)(player->pos_x + player->dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y + player->dir_y * player->move_speed);
	if (is_wall(game, new_map_x, new_map_y))
		return ;
	player->pos_x += player->dir_x * player->move_speed;
	player->pos_y += player->dir_y * player->move_speed;
}

void	move_backward(t_game *game)
{
	t_player	*player;
	int			new_map_x;
	int			new_map_y;
	
	player = &game->player;
	new_map_x = (int)(player->pos_x - player->dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y - player->dir_y * player->move_speed);
	if (is_wall(game, new_map_x, new_map_y))
		return ;
	player->pos_x -= player->dir_x * player->move_speed;
	player->pos_y -= player->dir_y * player->move_speed;
}

void	move_rightward(t_game *game)
{
	int			new_map_x;
	int			new_map_y;
	double		temp_dir_x;
	double		temp_dir_y;
	t_player	*player;

	player = &game->player;
	temp_dir_x = player->dir_y; 
	temp_dir_y = player->dir_x; 
	new_map_x = (int)(player->pos_x + temp_dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y - temp_dir_y * player->move_speed);
	if (is_wall(game, new_map_x, new_map_y))
		return ;
	player->pos_x += temp_dir_x * player->move_speed;
	player->pos_y -= temp_dir_y * player->move_speed;
}

void	move_leftward(t_game *game)
{
	int			new_map_x;
	int			new_map_y;
	double		temp_dir_x;
	double		temp_dir_y;
	t_player	*player;

	player = &game->player;
	temp_dir_x = player->dir_y; 
	temp_dir_y = player->dir_x; 
	new_map_x = (int)(player->pos_x - temp_dir_x * player->move_speed);
	new_map_y = (int)(player->pos_y + temp_dir_y * player->move_speed);
	if (is_wall(game, new_map_x, new_map_y))
		return ;
	player->pos_x -= temp_dir_x * player->move_speed;
	player->pos_y += temp_dir_y * player->move_speed;
}

void	turn_right(t_game *game)
{
	double		temp_dir_x;
	double		temp_plane_x;
	double		rot_speed;
	t_player	*player;

	player = &game->player;
	temp_dir_x = player->dir_x;
	temp_plane_x = player->plane_x;
	rot_speed = player->rot_speed;
	player->dir_x = temp_dir_x * cos(-rot_speed) - player->dir_y * sin(-rot_speed);
	player->dir_y = temp_dir_x * sin(-rot_speed) + player->dir_y * cos(-rot_speed);
	player->plane_x = temp_plane_x * cos(-rot_speed) - player->plane_y * sin(-rot_speed);
	player->plane_y = temp_plane_x * sin(-rot_speed) + player->plane_y * cos(-rot_speed);
}

void	turn_left(t_game *game)
{
	double		temp_dir_x;
	double		temp_plane_x;
	double		rot_speed;
	t_player	*player;

	player = &game->player;
	temp_dir_x = player->dir_x;
	temp_plane_x = player->plane_x;
	rot_speed = player->rot_speed;
	player->dir_x = temp_dir_x * cos(rot_speed) - player->dir_y * sin(rot_speed);
	player->dir_y = temp_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	player->plane_x = temp_plane_x * cos(rot_speed) - player->plane_y * sin(rot_speed);
	player->plane_y = temp_plane_x * sin(rot_speed) + player->plane_y * cos(rot_speed);
}

void	update_player(t_game *game)
{
	if (game->key_code == KEY_W)
		move_forward(game);
	else if (game->key_code == KEY_S)
		move_backward(game);
	if (game->key_code == KEY_D)
		move_rightward(game);
	else if (game->key_code == KEY_A)
		move_leftward(game);
	if (game->key_code == KEY_RIGHT)
		turn_right(game);
	else if (game->key_code == KEY_LEFT)
		turn_left(game);
	game->key_code = -1;
}

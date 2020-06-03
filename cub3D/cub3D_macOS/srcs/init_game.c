/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:03:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 21:20:50 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "get_next_line.h"
#include "libft.h"

void	set_player_pos_and_dir(t_game *game, int row, int col)
{
	double		rotate;
	double		temp_plane_x;
	double		temp_dir_x;
	t_player	*player;

	player = &game->player;
	game->player.pos_x = row + 0.5;
	game->player.pos_y = col + 0.5;
	rotate = 0;
	if (game->map.grid[row][col] == 'S')
		rotate = M_PI;
	else if (game->map.grid[row][col] == 'E')
		rotate = M_PI * 0.5;
	else if (game->map.grid[row][col] == 'W')
		rotate = M_PI * 1.5;
	game->map.grid[row][col] = '0';
	temp_dir_x = player->dir_x;
	temp_plane_x = player->plane_x;
	player->dir_x = temp_dir_x * cos(-rotate) - player->dir_y * sin(-rotate);
	player->dir_y = temp_dir_x * sin(-rotate) + player->dir_y * cos(-rotate);
	player->plane_x = temp_plane_x * cos(-rotate) - player->plane_y * sin(-rotate);
	player->plane_y = temp_plane_x * sin(-rotate) + player->plane_y * cos(-rotate);
}

void	set_item(t_game *game, int row, int col)
{
	static int	i = 0;

	game->item[i].x = row;
	game->item[i].y = col;
	game->item[i].dist = -1;
	i += 1;
}

void	set_player_and_item_pos(t_game *game)
{
	int		row;
	int		col;

	row = -1;
	while (game->map.grid[++row])
	{
		col = -1;
		while (game->map.grid[row][++col])
		{
			if (game->map.grid[row][col] == 'N' || game->map.grid[row][col] == 'S' ||
					game->map.grid[row][col] == 'E' || game->map.grid[row][col] == 'W')
				set_player_pos_and_dir(game, row, col);
			else if (game->map.grid[row][col] == '2')
				set_item(game, row, col);
		}
	}
}

void	init_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->move_speed = MOVE_SPEED;
	player->rot_speed = ROT_SPEED;
}

void	init_game(t_game *game, int argc, char *file)
{
	game->init_success = FALSE;
	game->map.row_count = 0;
	game->item_count = 0;
	game->moved = FALSE;
	if (!(parsing_file_to_game(file, game)))
		return ;
	if (!(game->zbuffer = (double *)malloc(sizeof(double) * game->screen_w)))
		return ;
	if (!(game->item = (t_item *)malloc(sizeof(t_item) * game->item_count)))
		return ;
	init_player(game);
	set_player_and_item_pos(game);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w, game->screen_h, "iwoo");
	game->rend.camera_x = 0;
	game->key_code = -1;
	if (!(open_img(game)))
		return ;
	if (argc == 3)
		game->save_option = TRUE;
	game->init_success = TRUE;
}

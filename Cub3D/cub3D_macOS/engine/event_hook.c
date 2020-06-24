/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 10:31:18 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		exit_game(t_game *game)
{
	free_double_arr(game->map.grid, game->map.row_count);
	free(game->zbuffer);
	free(game->item);
	free_textures(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}

int		press_key(int key, t_game *game)
{
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

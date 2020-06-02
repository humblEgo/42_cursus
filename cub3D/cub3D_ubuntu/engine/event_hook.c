/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 03:36:46 by iwoo             ###   ########.fr       */
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

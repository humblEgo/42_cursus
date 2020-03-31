/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:36:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/31 23:45:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	main_loop_process(t_game *game)
{
	static int	update = TRUE;

	if (game->player.move.x || game->player.move.y)
	{
		update = TRUE;
	}
	if (update)
	{
		render_player(game);
	}
	update = FALSE;
	return (0);
}

int	main(void)
{
	t_game		game;

	char grid[9][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	init_game(&game);
	game.map.map_grid = grid;
	game.window.mlx_ptr = mlx_init();
	game.window.win_ptr = mlx_new_window(game.window.mlx_ptr, 500, 500, "test");
//	render_map(&map, &window);
	mlx_hook(game.window.win_ptr, DEAL_KEY_PRESS, KeyPressMask, press_key, &game); 
	mlx_hook(game.window.win_ptr, DEAL_KEY_RELEASE, KeyReleaseMask, release_key, &game); 
	mlx_loop_hook(game.window.mlx_ptr, main_loop_process, &game);
	mlx_loop(game.window.mlx_ptr);
	return (0);
}

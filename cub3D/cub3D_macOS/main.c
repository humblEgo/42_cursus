/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:36:25 by iwoo              #+#    #+#             */
<<<<<<< HEAD:cub3D/main.c
/*   Updated: 2020/04/02 18:31:10 by iwoo             ###   ########.fr       */
=======
/*   Updated: 2020/05/20 23:37:29 by iwoo             ###   ########.fr       */
>>>>>>> 54bd4be898d4299136a13a7f3361a6e36c1f6423:cub3D/cub3D_macOS/main.c
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	main_loop_process(t_game *game)
{
	static int	update = TRUE;

	if (game->moved)
	{
		update = TRUE;
	}
	if (update)
	{
		update_player(game);
		mlx_clear_window(game->window.mlx_ptr, game->window.win_ptr);
		render_map(&game->map, &game->window);
		render_player(game);
	}
	game->moved = FALSE;
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
	game.map.grid = grid;
	game.window.mlx_ptr = mlx_init();
<<<<<<< HEAD:cub3D/main.c
	game.window.win_ptr = mlx_new_window(game.window.mlx_ptr, 500, 500, "test");
	mlx_hook(game.window.win_ptr, DEAL_KEY_PRESS, KeyPressMask, press_key, &game); 
	mlx_hook(game.window.win_ptr, DEAL_KEY_RELEASE, KeyReleaseMask, release_key, &game); 
=======
	game.window.win_ptr = mlx_new_window(game.window.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	mlx_hook(game.window.win_ptr, DEAL_KEY_PRESS, 1L << 0, press_key, &game); 
//	mlx_hook(game.window.win_ptr, DEAL_KEY_RELEASE, KeyReleaseMask, release_key, &game); 
>>>>>>> 54bd4be898d4299136a13a7f3361a6e36c1f6423:cub3D/cub3D_macOS/main.c
	mlx_loop_hook(game.window.mlx_ptr, main_loop_process, &game);
	mlx_loop(game.window.mlx_ptr);
	return (0);
}

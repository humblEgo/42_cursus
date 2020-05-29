/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:36:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/28 17:58:07 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"

int	main_loop_process(t_game *game)
{
	static int	update = TRUE;

	if (game->moved)
		update = TRUE;
	if (update)
	{
		update_player(game);
		render_screen(game);
	}
	game->moved = FALSE;
	update = FALSE;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game		game;

	char grid[MAP_HEIGHT][MAP_WIDTH] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 0, 1, 1, 0, 0, 0, 1, 1, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	if (!(argc == 2))
		return (error(ARG_ERROR));
//	if (is_valid_file(fd))
//		init_game(&game, argv[1]);
	init_game(&game, argv[1]);
	game.map.temp = grid;
	open_img(&game);
/* MAC OS KeyPressMask
	mlx_hook(game.win_ptr, DEAL_KEY_PRESS, 1L << 0, press_key, &game); 
//	mlx_hook(game.win_ptr, DEAL_KEY_RELEASE, 1L << 1, release_key, &game); 
*/
	if (game.init_success == FALSE)
		return (error(INIT_ERROR));
	mlx_hook(game.win_ptr, DEAL_KEY_PRESS, KeyPressMask, press_key, &game); 
	mlx_loop_hook(game.mlx_ptr, main_loop_process, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
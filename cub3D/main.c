/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:36:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/30 18:26:01 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	printf("%c\n", key);
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

	init_map(&game.map);
	init_player(&game.map, &game.player);
	game.map.map_grid = grid;
	game.window.mlx_ptr = mlx_init();
	game.window.win_ptr = mlx_new_window(game.window.mlx_ptr, 500, 500, "test");
//	render_map(&map, &window);
//
//	mlx_key_hook(window.win_ptr, deal_key, (void *)0); //3rd parameter means that I will not globally use 3rd parameter. 
	render_player(&game);
	mlx_loop(game.window.mlx_ptr);
	return (0);
}

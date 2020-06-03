/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 21:36:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 10:40:41 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"

int	is_valid_save_option(char *argv)
{
	if (ft_strlen(argv) != 6)
		return (FALSE);
	if (ft_strncmp("--save", argv, 6))
		return (FALSE);
	return (TRUE);
}

int	main_loop_process(t_game *game)
{
	static int	update = TRUE;

	if (game->moved)
		update = TRUE;
	if (update)
	{
		update_player(game);
		raycast_screen(game);
	}
	game->moved = FALSE;
	update = FALSE;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game		game;

	if (!(argc == 2 || (argc == 3 && is_valid_save_option(argv[2]))))
		return (error(ARG_ERROR));
	if (is_valid_file(&game, argv[1]))
	{
		init_game(&game, argc, argv[1]);
		if (game.init_success == FALSE)
			return (error(INIT_ERROR));
		mlx_hook(game.win_ptr, DEAL_KEY_PRESS, 1L << 0, press_key, &game); 
		mlx_hook(game.win_ptr, DEAL_DESTROY_NOTIFY, 1L << 17, esc_game, &game);
		mlx_loop_hook(game.mlx_ptr, main_loop_process, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}

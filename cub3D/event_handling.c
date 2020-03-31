/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 22:00:23 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/31 23:46:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		press_key(int key, t_game *game)
{
	if (key == 'w')
		game->player.pos_y++;
	else if (key == 's')
		game->player.pos_y--;
	else if (key == 'd')
		game->player.pos_x++;
	else if (key == 'a')
		game->player.pos_x--;
	game->player.move.x = TRUE;
	return (0);
}

int		release_key(int	key, t_game *game)
{
	if (key == 'w')
		game->player.pos_y++;
	else if (key == 's')
		game->player.pos_y--;
	else if (key == 'd')
		game->player.pos_x++;
	else if (key == 'a')
		game->player.pos_x--;
	game->player.move.x = FALSE;
	return (0);
}

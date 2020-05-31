/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:23:16 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/21 16:28:08 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "ft_cub3d_test.h"

void	init_game_test(t_game *game)
{
	printf("pos_x: %f\n", game->player.pos_x);
	printf("pos_y: %f\n", game->player.pos_y);
	printf("dir_x: %f\n", game->player.dir_x);
	printf("dir_y: %f\n", game->player.dir_y);
	printf("plane_x: %f\n", game->player.plane_x);
	printf("plane_y: %f\n", game->player.plane_y);
	printf("move_speed: %f\n", game->player.move_speed);
	printf("rot_speed: %f\n", game->player.rot_speed);
}

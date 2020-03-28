/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:26:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/28 22:56:14 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define _USE_MATH_DEFINES

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

typedef struct	s_map
{
	int		height;
	int		width;
	int		tile_h;
	int		tile_w;
	int		color;
	char	(*map_grid)[10];
}				t_map;

typedef struct	s_ray
{
	double	angle;
	int		color;
}				t_ray;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	int		color;
	t_ray	ray;
}				t_player;

void	init_map(t_map *map);
void	init_player(t_map *map, t_player *player);
void	render_tile(int x, int y, t_map *map, t_window *window);
void	render_map(t_map *map, t_window *window);
void	render_player(t_map *map, t_window *window, t_player *player);

int		get_rad(int num);
#endif

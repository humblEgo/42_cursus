/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:26:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/31 23:27:36 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define _USE_MATH_DEFINES

# define TRUE 1
# define FALSE 0
# define DEAL_KEY_PRESS 2
# define DEAL_KEY_RELEASE 3

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/Xlib.h>
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

typedef struct	s_move
{
	double	x;
	double	y;
}				t_move;

typedef	struct	s_rotate
{
	double	r;
	double	l;
}				t_rotate;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	int			color;
	t_rotate	rotate;
	t_move		move;
	t_ray		ray;
}				t_player;

typedef struct	s_game
{
	t_map		map;
	t_window	window;
	t_player	player;
}				t_game;

void	init_map(t_map *map);
void	init_player(t_map *map, t_player *player);
void	init_game(t_game *game);

void	render_tile(int x, int y, t_map *map, t_window *window);
void	render_map(t_map *map, t_window *window);
void	render_ray(t_map *map, t_window *window, t_player *player);
void	render_player(t_game *game);
int		press_key(int key, t_game *game);
int		release_key(int key, t_game *game);

double	get_rad(int num);
#endif

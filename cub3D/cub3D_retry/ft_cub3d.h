/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:26:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/22 22:29:43 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define _USE_MATH_DEFINES

# define TRUE 1
# define FALSE 0

# define DEAL_KEY_PRESS 2
# define DEAL_KEY_RELEASE 3

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_W 13 
# define KEY_S 1 
# define KEY_D 2
# define KEY_A 0

# define KEY_ESC 53

# define MOVE_SPEED 0.3
# define ROT_SPEED 0.1 

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480 
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define MAP_WIDTH 10
# define MAP_HEIGHT 10

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
	char	(*grid)[10];
}				t_map;

typedef struct	s_img
{
	int		*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		*data;
}				t_img;


typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		move_speed;
	double		rot_speed;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}				t_player;

typedef struct	s_game
{
	t_map		map;
	t_window	window;
	t_player	player;
	int			key_code;
	int			moved;
}				t_game;

void			init_game(t_game *game);

void			render_screen(t_game *game);
void			update_player(t_game *game);
int				press_key(int key, t_game *game);
#endif

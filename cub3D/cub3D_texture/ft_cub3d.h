/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:26:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/28 23:25:48 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define _USE_MATH_DEFINES

# define TRUE 1
# define FALSE 0

# define DEAL_KEY_PRESS 2
# define DEAL_KEY_RELEASE 3

/* MAC OS KEY SETTINGS

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_W 13 
# define KEY_S 1 
# define KEY_D 2
# define KEY_A 0

# define KEY_ESC 53
*/

/* UBUNTU KEY SETTINGS */

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define KEY_W 119
# define KEY_S 115 
# define KEY_D 100
# define KEY_A 97

/* UBUNTU KEY  SETTINGS */

# define MOVE_SPEED 0.3
# define ROT_SPEED 0.1 

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480 
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define MAP_WIDTH 10
# define MAP_HEIGHT 10

# define ARG_ERROR -1 
# define INIT_ERROR -2 
# define FILE_ERROR -3

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

/* UBUNTU SETTING */
# include <X11/Xlib.h>
/* UBUNTU SETTING */

typedef struct	s_map
{
	char	(*temp)[10];
	int		row_count;
	char	**grid;
}				t_map;

typedef struct	s_img
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		*data;
	char	*file;
	int		width;
	int		height;
	double	tex_x;
	double	tex_y;
}				t_img;

typedef	struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;

typedef struct	s_render
{
	int			map_x;
	int			map_y;
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
}				t_render;


typedef	struct	s_vertical_line
{
	int			height;
	int			start;
	int			end;
}				t_vertical_line;

typedef	struct	s_color
{
	int			floor;
	int			ceiling;
}				t_color;

typedef struct	s_game
{
	t_map		map;
	t_player	player;
	t_render	rend;
	t_img		texture[5];
	t_color		color;
	void		*mlx_ptr;
	void		*win_ptr;
	int			screen_w;
	int			screen_h;
	int			key_code;
	int			moved;
	double		zbuffer[SCREEN_WIDTH];
	int			init_success;
	int			**map_grid;
}				t_game;

void			init_game(t_game *game, char *file);

void			render_screen(t_game *game);
void			update_player(t_game *game);
int				press_key(int key, t_game *game);
int				release_key(int key, t_game *game);

void			open_img(t_game *game);

int				error(int error_type);

void			free_double_arr(char **arr, int n);

#endif

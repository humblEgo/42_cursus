/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:26:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/01 21:01:35 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define _USE_MATH_DEFINES

# define TRUE 1
# define FALSE 0

# define DEAL_KEY_PRESS 2
# define DEAL_DESTROY_NOTIFY 17

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
# define KEY_ESC 65307

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
# define CUB_FILE_ERROR -3
# define CUB_FILE_OPEN_ERROR -4
# define TEXTURE_FILE_ERROR -5
# define SAVE_FILE_ERROR -6

# define MAP_FACTORS "012 NSWE"

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
	int		tex_x;
	int		tex_y;
	int		color;
}				t_img;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef	struct	s_rend_item
{
	double		x;
	double		y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			screen_x;
	int			height;
	int			width;
}				t_rend_item;

typedef struct	s_render
{
	int			map_x;
	int			map_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;

	double		floor_x_wall;
	double		floor_y_wall;
	double		current_dist;
	double		weight;
	double		current_floor_x;
	double		current_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;
}				t_render;

typedef	struct	s_line
{
	int			height;
	int			start;
	int			end;
}				t_line;

typedef	struct	s_color
{
	int			floor;
	int			ceiling;
}				t_color;

typedef	struct	s_item
{
	double		x;
	double		y;
	double		dist;
}				t_item;

typedef	struct	s_valid
{
	int			render_size;
	int			tex_no;
	int			tex_so;
	int			tex_we;
	int			tex_ea;
	int			tex_s;
	int			color_floor;
	int			color_ceiling;
	int			map_player;
	int			map;
}				t_valid;


typedef struct	s_game
{
	t_map		map;
	t_player	player;
	t_render	rend;
	t_img		texture[7];
	t_color		color;
	t_item		*item;
	t_valid		valid;
	int			item_count;
	void		*mlx_ptr;
	void		*win_ptr;
	int			screen_w;
	int			screen_h;
	int			key_code;
	int			moved;
	double		*zbuffer;
	int			init_success;
	int			x;
	int			y;
	int			save_option;
	int			floor_ceiling_texture;
}				t_game;

void			init_game(t_game *game, int argc, char *file);
void			add_line_to_map_grid(t_game *game, char *line);
void			get_map_grid(t_game *game, char *line);

void			render_screen(t_game *game);
void			update_player(t_game *game);
int				press_key(int key, t_game *game);
int				exit_game(t_game *game);

int				open_img(t_game *game);

int				error(int error_type);

void			free_double_arr(char **arr, int n);

void			calculate_dist_from_wall(t_game *game);
void			fill_item_image(t_game *game, t_img *screen);

int				is_valid_file(t_game *game, char *line);
int				is_valid_save_option(char *argv);

int				save_bmp(t_game *game, t_img *screen);
#endif

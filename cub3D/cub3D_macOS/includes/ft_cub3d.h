/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:26:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 10:41:23 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define _USE_MATH_DEFINES

# define TRUE 1
# define FALSE 0

# define DEAL_KEY_PRESS 2
# define DEAL_DESTROY_NOTIFY 17
# define KEY_PRESS_MASK 1L<<0
# define STRUCTURE_NOTIFY_MASK 1L<<17

define KEY_UP 126
define KEY_DOWN 125
define KEY_RIGHT 124
define KEY_LEFT 123

define KEY_W 13 
define KEY_S 1 
define KEY_D 2
define KEY_A 0
define KEY_ESC 53

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
# define SAVING_FILE_ERROR -6
# define GETTING_MAP_ERROR -7

# define MAP_FACTORS "012 NSWE"
# define MAX_SCREEN_W 1920
# define MIN_SCREEN_W 640
# define MAX_SCREEN_H 1080
# define MIN_SCREEN_H 480

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

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

/*
**				is_valid_file.c
*/

int				is_valid_file(t_game *game, char *file);
void			init_valid_factor(t_game *game);
void			check_map_info_and_get_map(t_game *game, int fd);
int				is_all_factors_valid(t_game *game);

/*
**				valid_check_1.c
*/

int				is_valid_map_size_info(char *line);
int				is_valid_wall_texture(char *line);
int				is_valid_item_floor_ceiling_texture(char *line);
void			check_valid_texture_info(t_game *game, char *line);

/*
**				valid_check_2.c
*/

int				is_valid_rgb_values(char **rgb);
int				is_valid_color(char *line);
void			check_valid_color_info(t_game *game, char *line);
int				is_closed_map(t_game *game, int i, int j);
int				is_valid_map(t_game *game);

/*
**				parsing_map_info.c
*/

void			get_render_size(t_game *game, char *line);
void			get_texture(t_game *game, char *line);
void			get_floor_and_ceiling_color(t_game *game, char *line);
void			get_floor_and_ceiling(t_game *game, char *line);
int				parsing_file_to_game(char *file, t_game *game);

/*
**				parsing_map_grid.c
*/

int				add_line_to_map_grid(t_game *game, char *line);
int				get_map_grid(t_game *game, char *line);
int				count_item(char *line);

/*
**				init_game.c
*/

void			set_player_pos_and_dir(t_game *game, int row, int col);
void			set_item(t_game *game, int row, int col);
void			set_player_and_item_pos(t_game *game);
void			init_player(t_game *game);
void			init_game(t_game *game, int argc, char *file);

/*
**				update_player.c
*/

int				is_wall(t_game *game, int new_map_x, int new_map_y);
void			move_forward_or_backward(t_game *game);
void			move_rightward_or_leftward(t_game *game);
void			turn_pov(t_game *game);
void			update_player(t_game *game);

/*
**				event_hook.c
*/

int				exit_game(t_game *game);
int				press_key(int key, t_game *game);

/*
**				render_screen.c
*/

void			init_wall_info(t_game *game, t_img wall_texture, t_line draw_line);
void			fill_map_image(t_game *game, t_img *screen, t_line draw_line, t_img wall_texture);
t_line			get_draw_line(t_game *game);
t_img			get_wall_texture(t_game *game);
void			raycast_screen(t_game *game);

/*
**				fill_texture_to_floor_ceiling.c
*/

void			set_floor_wall(t_game *game);
void			fill_texture_to_floor_ceiling(t_game *game, t_img *screen, t_line draw_line);

/*
**				calculate_dist_from_wall.c
*/

void			set_camera_raydir_currentpos(t_game *game);
void			set_deltadist_sidedist_step(t_game *game);
void			find_wall_grid(t_game *game);
void			set_perp_dist_between_player_and_wall(t_game *game);
void			calculate_dist_from_wall(t_game *game);

/*
**				fill_item_image.c
*/

void			sort_item_by_distance(t_game *game, t_item *item);
void			set_item_distance(t_game *game, t_item *item);
void			calculate_rendering_item_info(t_game *game, t_item *item, t_rend_item *rd_item);
void			fill_item_image_color(t_game *game, t_rend_item *rd_item, t_img img_item, t_img *screen);
void			fill_item_image(t_game *game, t_img *screen);

/*
**				error.c
*/

int				error(int error_type);

/*
**				open_img.c
*/

int				open_img(t_game *game);

/*
**				utils.c
*/

int				ft_count_strings(char **split);
int				is_num_str(char *str);
int				is_correct_num_of_splits(char **split, int correct_num);
void			free_double_arr(char **arr, int n);
void			free_textures(t_game *game);

/*
**				save_bmp.c
*/

int				is_valid_save_option(char *argv);
int				save_bmp(t_game *game, t_img *screen);
#endif

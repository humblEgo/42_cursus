/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:03:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/01 21:53:19 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "get_next_line.h"
#include "libft.h"

void	get_render_size(t_game *game, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	game->screen_w = ft_atoi(split[1]);
	game->screen_h = ft_atoi(split[2]);
	line = NULL;
	free_double_arr(split, 3);
}

void	get_texture(t_game *game, char *line)
{
	char	**split;
	char	*file;

	split = ft_split(line, ' ');
	file = split[1];
	if (!ft_strncmp("NO", line, 2))
		game->texture[0].file = ft_strdup(file);
	else if (!ft_strncmp("SO", line, 2))
		game->texture[1].file = ft_strdup(file);
	else if (!ft_strncmp("WE", line, 2))
		game->texture[2].file = ft_strdup(file);
	else if (!ft_strncmp("EA", line, 2))
		game->texture[3].file = ft_strdup(file);
	else if (!ft_strncmp("S", line, 1))
		game->texture[4].file = ft_strdup(file);
	else if (!ft_strncmp("F", line, 1))
		game->texture[5].file = ft_strdup(file);
	else if (!ft_strncmp("C", line, 1))
		game->texture[6].file = ft_strdup(file);
	free_double_arr(split, 2);
}

void	get_floor_and_ceiling_color(t_game *game, char *line)
{
	char	**rgb;
	int		temp;

	rgb = ft_split(&line[2], ',');
	temp = ft_atoi(rgb[0]) * 16 * 16 * 16 * 16;
	temp += ft_atoi(rgb[1]) * 16 * 16;
	temp += ft_atoi(rgb[2]);
	if (!ft_strncmp("F", line, 1))
		game->color.floor = temp;
	else
		game->color.ceiling = temp;
 	free_double_arr(rgb, 3);
}

void	get_floor_and_ceiling(t_game *game, char *line)
{
	if (game->floor_ceiling_texture == TRUE)
		get_texture(game, line);
	else
		get_floor_and_ceiling_color(game, line);
}

void	add_line_to_map_grid(t_game *game, char *line)
{
	char**	temp;
	int		i;

	if (!(temp = (char **)malloc(sizeof(char *) * (game->map.row_count + 2))))
		return ;
	i = -1;
	while (++i < game->map.row_count)
		temp[i] = ft_strdup(game->map.grid[i]);
	temp[i] = ft_strdup(line);
	temp[i + 1] = NULL;
	free_double_arr(game->map.grid, game->map.row_count);
	game->map.grid = temp;
}

void	get_map_grid(t_game *game, char *line)
{
	if (game->map.row_count == 0)
	{
		if (!(game->map.grid = (char **)malloc(sizeof(char *) * 2)))
			return ;
		game->map.grid[0] = ft_strdup(line);
		game->map.grid[1] = NULL;
	}
	else
		add_line_to_map_grid(game, line);
	game->map.row_count += 1;
}

int	count_item(char *line)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (++i < (int)ft_strlen(line))
		if (line[i] == '2')
			count += 1;
	return (count);
}

int	parsing_file_to_game(char *file, t_game *game)
{
	char	*line;
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (error(CUB_FILE_OPEN_ERROR));
	while (get_next_line(fd, &line))
	{
		if (!ft_strncmp("R", line, 1))
			get_render_size(game, line);
		else if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) 
					|| !ft_strncmp("WE", line, 2) || !ft_strncmp("EA", line, 2) || !ft_strncmp("S", line, 1))
			get_texture(game, line);
		else if (!ft_strncmp("F", line, 1) || !ft_strncmp("C", line, 1))
			get_floor_and_ceiling(game, line);
		else if (ft_strlen(line))
		{
			get_map_grid(game, line);
			game->item_count += count_item(line);
		}
		else
			free(line);
	}
	close(fd);
	return (TRUE);
}

void	set_player_pos_and_dir(t_game *game, int row, int col)
{
	char		dir;
	double		rotate;
	double		temp_plane_x;
	double		temp_dir_x;
	t_player	*player;

	player = &game->player;
	dir = game->map.grid[row][col];
	game->player.pos_x = row + 0.5;
	game->player.pos_y = col + 0.5;
	game->map.grid[row][col] = '0';
	if (dir == 'N')
		return ;
	else if (dir == 'S')
		rotate = M_PI;
	else if (dir == 'E')
		rotate = M_PI * 0.5;
	else if (dir == 'W')
		rotate = M_PI * 1.5;
	printf("rotate: %f\n", rotate);
	temp_dir_x = player->dir_x;
	temp_plane_x = player->plane_x;
	player->dir_x = temp_dir_x * cos(-rotate) - player->dir_y * sin(-rotate);
	player->dir_y = temp_dir_x * sin(-rotate) + player->dir_y * cos(-rotate);
	player->plane_x = temp_plane_x * cos(-rotate) - player->plane_y * sin(-rotate);
	player->plane_y = temp_plane_x * sin(-rotate) + player->plane_y * cos(-rotate);
}

void	set_item(t_game *game, int row, int col)
{
	static int	i = 0;

	game->item[i].x = row;
	game->item[i].y = col;
	game->item[i].dist = -1;
	i += 1;
}

void	set_player_and_item_pos(t_game *game)
{
	int		row;
	int		col;

	row = -1;
	while (game->map.grid[++row])
	{
		col = -1;
		while (game->map.grid[row][++col])
		{
			if (game->map.grid[row][col] == 'N' || game->map.grid[row][col] == 'S' ||
					game->map.grid[row][col] == 'E' || game->map.grid[row][col] == 'W')
				set_player_pos_and_dir(game, row, col);
			else if (game->map.grid[row][col] == '2')
				set_item(game, row, col);
		}
	}
}

void	init_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->move_speed = MOVE_SPEED;
	player->rot_speed = ROT_SPEED;
}

void	init_game(t_game *game, int argc, char *file)
{
	int i;

	game->init_success = FALSE;
	game->map.row_count = 0;
	game->item_count = 0;
	if (!(parsing_file_to_game(file, game)))
		return ;
	if (!(game->zbuffer = (double *)malloc(sizeof(double) * game->screen_w)))
		return ;
	if (!(game->item = (t_item *)malloc(sizeof(t_item) * game->item_count)))
		return ;
	init_player(game);
	set_player_and_item_pos(game);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w, game->screen_h, "iwoo");
	game->rend.camera_x = 0;
	game->key_code = -1;
	if (!(open_img(game)))
		return ;
	if (argc == 3)
		game->save_option = TRUE;
	game->init_success = TRUE;

	// test
	printf("screen_w %d\n", game->screen_w);
	printf("screen_h %d\n", game->screen_h);
	for(i = 0; i < 5; i++)
		printf("%s\n", game->texture[i].file);
	printf("%X\n%X\n", game->color.floor, game->color.ceiling);
	printf("%s\n", file);
	i = -1;
	while (game->map.grid[++i])
		printf("%s\n", game->map.grid[i]);
	printf("rows %d\n", game->map.row_count);
	i = -1;
	while (++i < game->item_count)
		printf("itme[%d] x: %f y: %f\n", i, game->item[i].x, game->item[i].y);
	// test
}

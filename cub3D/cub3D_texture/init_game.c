/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:03:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/28 22:47:47 by iwoo             ###   ########.fr       */
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
	free_double_arr(split, 2);
}

void	get_floor_and_celing_color(t_game *game, char *line)
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

int	parsing_file_to_game(char *file, t_game *game)
{
	char	*line;
	int		fd;

	if ((fd = open(file, O_RDONLY)) <= 0)
		return(error(FILE_ERROR));
	while (get_next_line(fd, &line))
	{
		if (!ft_strncmp("R", line, 1))
			get_render_size(game, line);
		else if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) 
					|| !ft_strncmp("WE", line, 2) || !ft_strncmp("EA", line, 2) || !ft_strncmp("S", line, 1))
			get_texture(game, line);
		else if (!ft_strncmp("F", line, 1) || !ft_strncmp("C", line, 1))
			get_floor_and_celing_color(game, line);
		else if (ft_strlen(line))
			get_map_grid(game, line);
		else
			free(line);
	}
	close(fd);
	return (1);
}

void	init_game(t_game *game, char *file)
{
	int i;

	game->map.row_count = 0;
	if (!(parsing_file_to_game(file, game)))
		game->init_success = FALSE;
	// test
	printf("screen_w %d\n", game->screen_w);
	printf("screen_h %d\n", game->screen_h);
	for(i = 0; i < 5; i++)
		printf("%s\n", game->texture[i].file);
	printf("%d\n%d\n", game->color.floor, game->color.ceiling);
	printf("%s\n", file);
	i = -1;
	while (game->map.grid[++i])
		printf("%s\n", game->map.grid[i]);
	double x = 5.0;
	double y = 5.0;
	printf("grid[%f][%f] = %d\n", x, y, game->map.grid[(int)x][(int)y]);
	printf("rows %d\n", game->map.row_count);
	// test
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w, game->screen_h, "test");
	game->player.pos_x = x;
	game->player.pos_y = y;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.camera_x = 0;
	game->player.move_speed = MOVE_SPEED;
	game->player.rot_speed = ROT_SPEED;
	game->key_code = -1;
	game->init_success = TRUE;
}

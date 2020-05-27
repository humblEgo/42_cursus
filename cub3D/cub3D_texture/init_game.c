/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:03:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/28 01:06:12 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "get_next_line.h"
#include "libft.h"

void	get_render_size(t_game *game, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	printf("%s\n", line);
	game->screen_w = ft_atoi(split[1]);
	game->screen_h = ft_atoi(split[2]);
	printf("%d\n", game->screen_w);
	printf("%d\n", game->screen_h);
	line = NULL;
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
}

void	get_floor_and_celing_color(t_game *game, char *line)
{
	char	**rgb;
	int		temp;

	rgb = ft_split(&line[2], ',');
	printf("%s\n", rgb[0]);
	printf("%s\n", rgb[1]);
	printf("%s\n", rgb[2]);
	temp = ft_atoi(rgb[0]) * 16 * 16 * 16 * 16;
	printf("%d\n", temp);
	temp += ft_atoi(rgb[1]) * 16 * 16;
	temp += ft_atoi(rgb[2]);
	if (!ft_strncmp("F", line, 1))
		game->color.floor = temp;
	else
		game->color.ceiling = temp;
	//TODO seg fault 잡기
// 	free_split(rgb, 3);
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
		else
			free(line);
	}
	close(fd);
	return (1);
}


void	init_game(t_game *game, char *file)
{
	if (!(parsing_file_to_game(file, game)))
		game->init_success = FALSE;
	for(int i = 0; i < 5; i++)
		printf("%s\n", game->texture[i].file);
	printf("%d\n, %d\n", game->color.floor, game->color.ceiling);
	printf("%s\n", file);
	game->screen_w = SCREEN_WIDTH;
	game->screen_h = SCREEN_HEIGHT;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w, game->screen_h, "test");
	game->player.pos_x = 5;
	game->player.pos_y = 6;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.camera_x = 0;
	game->player.move_speed = MOVE_SPEED;
	game->player.rot_speed = ROT_SPEED;
	game->map.width = MAP_WIDTH;
	game->map.height = MAP_HEIGHT;
	game->key_code = -1;
	game->texture[0].file = "./images/redbrick.xpm";
	game->texture[1].file = "./images/greystone.xpm";
	game->texture[2].file = "./images/wood.xpm";
	game->texture[3].file = "./images/eagle.xpm";
	game->texture[4].file = "./images/ITEM.xpm";
	game->init_success = TRUE;
}

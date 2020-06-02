/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:03:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 02:37:55 by iwoo             ###   ########.fr       */
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
	line = NULL;
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
		else if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) || !ft_strncmp("WE", line, 2)
				|| !ft_strncmp("EA", line, 2) || !ft_strncmp("S", line, 1))
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

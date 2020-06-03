/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:00:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 09:36:17 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"
#include "get_next_line.h"

void	init_valid_factor(t_game *game)
{
	game->map.row_count = 0;
	game->valid.render_size = FALSE;
	game->valid.tex_no = FALSE;
	game->valid.tex_so = FALSE;
	game->valid.tex_we = FALSE;
	game->valid.tex_ea = FALSE;
	game->valid.tex_s = FALSE;
	game->valid.color_floor = FALSE;
	game->valid.color_ceiling = FALSE;
	game->valid.map_player = FALSE;
	game->valid.map = FALSE;
	game->floor_ceiling_texture = FALSE;
	game->save_option = FALSE;
}

int		is_all_factors_valid(t_game *game)
{
	t_valid	valid;

	valid = game->valid;
	if (valid.render_size != TRUE)
		return (FALSE);
	if (valid.tex_no != TRUE || valid.tex_so != TRUE || valid.tex_we != TRUE 
			|| valid.tex_ea != TRUE || valid.tex_s != TRUE)
		return (FALSE);
	if (game->valid.color_floor != TRUE || game->valid.color_ceiling != TRUE)
		return (FALSE);
	if (game->valid.map_player != TRUE || game->valid.map != TRUE)
		return (FALSE);
	return (TRUE);
}

void	check_map_info_and_get_map(t_game *game, int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!ft_strncmp("R", line, 1))
			game->valid.render_size += is_valid_map_size_info(line);
		else if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) || !ft_strncmp("WE", line, 2)
				|| !ft_strncmp("EA", line, 2) || !ft_strncmp("S", line, 1))
			check_valid_texture_info(game, line);
		else if (!ft_strncmp("F", line, 1) || !ft_strncmp("C", line, 1))
			check_valid_color_info(game, line);
		else if (ft_strlen(line))
			get_map_grid(game, line);
		free(line);
	}
	free(line);
}

int	is_valid_file(t_game *game, char *file)
{
	int		fd;

	init_valid_factor(game);
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (error(CUB_FILE_ERROR));
	check_map_info_and_get_map(game, fd);
	close(fd);
	if (is_valid_map(game) && is_all_factors_valid(game))
	{
		free_double_arr(game->map.grid, game->map.row_count);
		return (TRUE);
	}
	free_double_arr(game->map.grid, game->map.row_count);
	return (error(CUB_FILE_ERROR));
}

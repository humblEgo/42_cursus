/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:00:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 00:32:26 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"
#include "get_next_line.h"

int	is_valid_map_size_info(char *line)
{
	char	**split;
	int		screen_w;
	int		screen_h;
	int		count;

	split = ft_split(line, ' ');
	count = -1;
	while (split[++count])
		if (count > 2)
			return (FALSE);
	if (!(split[0][0] == 'R' && ft_strlen(split[0]) == 1))
		return (FALSE);
	screen_w = ft_atoi(split[1]);
	screen_h = ft_atoi(split[2]);
	if (screen_w < 640 || screen_w > 1920)
		return (FALSE);
	if (screen_h < 480 || screen_h > 1080)
		return (FALSE);
	return (TRUE);
}

int	is_valid_wall_texture(char *line)
{
	char	**split;
	int		count;
	int		len;

	split = ft_split(line, ' ');
	count = -1;
	while (split[++count])
		if (count > 1)
			return (FALSE);
	if (!(ft_strlen(split[0]) == 2))
		return (FALSE);
	len = ft_strlen(split[1]);
	if (ft_strncmp(".xpm", &split[1][len - 4], 4))
		return (FALSE);
	return (TRUE);
}

int	is_valid_item_texture(char *line)
{
	char	**split;
	int		count;
	int		len;

	split = ft_split(line, ' ');
	count = -1;
	while (split[++count])
		if (count > 1)
			return (FALSE);
	if (!(ft_strlen(split[0]) == 1))
		return (FALSE);
	len = ft_strlen(split[1]);
	if (ft_strncmp(".xpm", &split[1][len - 4], 4))
		return (FALSE);
	return (TRUE);
}

void	check_valid_texture_info(t_game *game, char *line)
{
	if (!ft_strncmp("NO", line, 2))
		game->valid.tex_no += is_valid_wall_texture(line);
	else if (!ft_strncmp("WE", line, 2))
		game->valid.tex_we += is_valid_wall_texture(line);
	else if (!ft_strncmp("EA", line, 2))
		game->valid.tex_ea += is_valid_wall_texture(line);
	else if (!ft_strncmp("SO", line, 2))
		game->valid.tex_so += is_valid_wall_texture(line);
	else if (!ft_strncmp("S", line, 1))
		game->valid.tex_s += is_valid_item_texture(line);
}

int	is_num_str(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
	return (TRUE);
}

int	is_valid_color(char *line)
{
	char	**split;
	char	**rgb;
	int		count;
	int		rgb_value;

	split = ft_split(line, ' ');
	count = -1;
	while (split[++count])
		if (count > 1)
			return (FALSE);
	if (!(ft_strlen(split[0]) == 1))
		return (FALSE);
	free(split[0]);
	rgb = ft_split(split[1], ',');
	free(split[1]);
	count = -1;
	while (rgb[++count])
	{
		if (count > 2)
			return (FALSE);
		if (!is_num_str(rgb[count]))
			return (FALSE);
		rgb_value = ft_atoi(rgb[count]);
		if (!(rgb_value < 256 && rgb_value >= 0))
			return (FALSE);
	}
	return (TRUE);
}

void	check_valid_color_info(t_game *game, char *line)
{
	int len;

	len = ft_strlen(line);
	if (len < 6)
		return ;
	if (!ft_strncmp("F", line, 1))
		if (!ft_strncmp(".xpm", &line[len - 4], 4) && (game->floor_ceiling_texture = TRUE))
			game->valid.color_floor += TRUE;
		else
			game->valid.color_floor += is_valid_color(line);
	else if (!ft_strncmp("C", line, 1))
		if (!ft_strncmp(".xpm", &line[len - 4], 4) && (game->floor_ceiling_texture = TRUE))
			game->valid.color_ceiling += TRUE;
		else
			game->valid.color_ceiling += is_valid_color(line);
	else
		return ;
}

int		is_closed_map(t_game *game, int i, int j)
{
	if (i == 0 || i == game->map.row_count - 1
			|| j == 0 || (j == (int)ft_strlen(game->map.grid[i]) - 1))
		return (FALSE);
	if (game->map.grid[i + 1][j] == ' ' || 
			game->map.grid[i - 1][j] == ' ' ||
			game->map.grid[i][j + 1] == ' ' || 
			game->map.grid[i][j - 1] == ' ')
		return (FALSE);
	return (TRUE);
}

int		is_valid_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map.row_count)
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			if (!(ft_strchr(MAP_FACTORS, game->map.grid[i][j])))
				return (FALSE);
			if (ft_strchr("NSEW", game->map.grid[i][j]))
				game->valid.map_player += TRUE;
			if (game->map.grid[i][j] == '0' || game->map.grid[i][j] == '2')
				if (!(is_closed_map(game, i, j)))
				{
					free_double_arr(game->map.grid, game->map.row_count);
					return (FALSE);
				}
		}
	}
	free_double_arr(game->map.grid, game->map.row_count);
	return (game->valid.map = TRUE);
}

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

void	check_info_valid_and_get_map(t_game *game, int fd)
{
	char	*line;

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
		else
			free(line);
	}
}

int	is_valid_file(t_game *game, char *file)
{
	int		fd;

	init_valid_factor(game);
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (error(CUB_FILE_ERROR));
	check_info_valid_and_get_map(game, fd);
	close(fd);
	if (is_valid_map(game) && is_all_factors_valid(game))
		return (TRUE);
	return (error(CUB_FILE_ERROR));
}

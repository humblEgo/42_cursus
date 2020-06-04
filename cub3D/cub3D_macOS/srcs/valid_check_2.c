/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 02:03:33 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 18:06:54 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"
#include "get_next_line.h"

int		is_valid_rgb_values(char **rgb)
{
	int	rgb_value;
	int count;

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

int		is_valid_color(char *line)
{
	char	**split;
	int		res;
	char	**rgb;

	split = ft_split(line, ' ');
	res = TRUE;
	if (!is_correct_num_of_splits(split, 2))
		res = FALSE;
	if (ft_strlen(split[0]) != 1)
		res = FALSE;
	rgb = ft_split(split[1], ',');
	if (!is_valid_rgb_values(rgb))
		res = FALSE;
	free_double_arr(split, ft_count_strings(split));
	free_double_arr(rgb, ft_count_strings(rgb));
	return (res);
}

void	check_valid_color_info(t_game *game, char *line)
{
	int len;

	len = ft_strlen(line);
	if (len < 6)
		return ;
	if (!ft_strncmp("F", line, 1))
		if (!ft_strncmp(".xpm", &line[len - 4], 4)
				&& (game->floor_ceiling_texture = TRUE))
			game->valid.color_floor += is_valid_itm_flr_ciling_texture(line);
		else
			game->valid.color_floor += is_valid_color(line);
	else if (!ft_strncmp("C", line, 1))
		if (!ft_strncmp(".xpm", &line[len - 4], 4)
				&& (game->floor_ceiling_texture = TRUE))
			game->valid.color_ceiling += is_valid_itm_flr_ciling_texture(line);
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
	if (game->map.grid[i + 1][j] == ' '
			|| game->map.grid[i - 1][j] == ' '
			|| game->map.grid[i][j + 1] == ' '
			|| game->map.grid[i][j - 1] == ' ')
		return (FALSE);
	return (TRUE);
}

int		is_valid_map(t_game *game)
{
	int		i;
	int		j;
	char	map_factor;

	i = -1;
	while (++i < game->map.row_count)
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			map_factor = game->map.grid[i][j];
			if (!(ft_strchr(MAP_FACTORS, map_factor)))
				return (FALSE);
			if (ft_strchr("NSEW", map_factor))
				game->valid.map_player += TRUE;
			if (map_factor == '0' || map_factor == '2'
					|| map_factor == 'N' || map_factor == 'S'
					|| map_factor == 'W' || map_factor == 'E')
				if (!(is_closed_map(game, i, j)))
					return (FALSE);
		}
	}
	return (game->valid.map = TRUE);
}

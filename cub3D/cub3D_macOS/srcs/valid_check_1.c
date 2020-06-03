/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 02:03:33 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 14:02:15 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"
#include "get_next_line.h"

int		is_valid_map_size_info(char *line)
{
	char	**split;
	int		screen_w;
	int		screen_h;

	split = ft_split(line, ' ');
	if (!is_correct_num_of_splits(split, 3) || ft_strcmp(split[0], "R"))
	{
		free_double_arr(split, ft_count_strings(split));
		return (FALSE);
	}
	screen_w = ft_atoi(split[1]);
	screen_h = ft_atoi(split[2]);
	free_double_arr(split, ft_count_strings(split));
	if (screen_w < MIN_SCREEN_W || screen_w > MAX_SCREEN_W)
		return (FALSE);
	if (screen_h < MIN_SCREEN_H || screen_h > MAX_SCREEN_H)
		return (FALSE);
	return (TRUE);
}

int		is_valid_wall_texture(char *line)
{
	char	**split;
	int		len;
	int		res;

	split = ft_split(line, ' ');
	res = TRUE;
	if (!is_correct_num_of_splits(split, 2))
		res = FALSE;
	if (ft_strlen(split[0]) != 2)
		res = FALSE;
	len = ft_strlen(split[1]);
	if (ft_strncmp(".xpm", &split[1][len - 4], 4))
		res = FALSE;
	free_double_arr(split, ft_count_strings(split));
	return (res);
}

int		is_valid_itm_flr_ciling_texture(char *line)
{
	char	**split;
	int		len;
	int		res;

	split = ft_split(line, ' ');
	res = TRUE;
	if (!is_correct_num_of_splits(split, 2))
		res = FALSE;
	if (ft_strlen(split[0]) != 1)
		res = FALSE;
	len = ft_strlen(split[1]);
	if (ft_strncmp(".xpm", &split[1][len - 4], 4))
		res = FALSE;
	free_double_arr(split, ft_count_strings(split));
	return (res);
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
		game->valid.tex_s += is_valid_itm_flr_ciling_texture(line);
}

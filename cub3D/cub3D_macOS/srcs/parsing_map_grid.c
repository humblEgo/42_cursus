/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:03:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 22:19:41 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "get_next_line.h"
#include "libft.h"

int	add_line_to_map_grid(t_game *game, char *line)
{
	char**	temp;
	int		i;

	if (!(temp = (char **)malloc(sizeof(char *) * (game->map.row_count + 2))))
	{
		free_double_arr(game->map.grid, game->map.row_count);
		return (error(GETTING_MAP_ERROR));
	}
	i = -1;
	while (++i < game->map.row_count)
		temp[i] = ft_strdup(game->map.grid[i]);
	temp[i] = ft_strdup(line);
	temp[i + 1] = NULL;
	free_double_arr(game->map.grid, game->map.row_count);
	game->map.grid = temp;
	return (TRUE);
}

int	get_map_grid(t_game *game, char *line)
{
	if (game->map.row_count == 0)
	{
		if (!(game->map.grid = (char **)malloc(sizeof(char *) * 2)))
			return (error(GETTING_MAP_ERROR));
		game->map.grid[0] = ft_strdup(line);
		game->map.grid[1] = NULL;
	}
	else
		add_line_to_map_grid(game, line);
	game->map.row_count += 1;
	return (TRUE);
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

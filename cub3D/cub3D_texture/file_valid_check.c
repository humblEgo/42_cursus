/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valid_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:00:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/30 19:48:53 by iwoo             ###   ########.fr       */
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

void	check_valid_texture_info(char *line, t_game *game)
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

void	init_valid_factor(t_game *game)
{
	game->valid.render_size = FALSE;
	game->valid.tex_no = FALSE;
	game->valid.tex_so = FALSE;
	game->valid.tex_we = FALSE;
	game->valid.tex_ea = FALSE;
	game->valid.tex_s = FALSE;
	game->valid.color_floor = FALSE;
	game->valid.color_ceiling = FALSE;
	game->valid.map= FALSE;
}

int		is_all_valid_factor(t_game *game)
{
	t_valid	valid;

	valid = game->valid;
	if (valid.render_size != TRUE)
		return (FALSE);
	if (valid.tex_no != TRUE || valid.tex_so != TRUE || valid.tex_we != TRUE 
			|| valid.tex_ea != TRUE || valid.tex_s != TRUE)
	{
		printf("no %d\n", valid.tex_no);
		printf("so %d\n", valid.tex_so);
		printf("we %d\n", valid.tex_we);
		printf("ea %d\n", valid.tex_ea);
		printf("s %d\n", valid.tex_s);
		return (FALSE);
	}
//	if (game->valid.color != TRUE)
//		return (FALSE);
//	if (game->valid.map != TRUE)
//		return (FALSE);
	return (TRUE);
}

int	is_valid_file(t_game *game, char *file)
{
	char	*line;
	int		res;
	int		fd;

	init_valid_factor(game);
	if ((fd = open(file, O_RDONLY)) <= 0)
		return(error(FILE_ERROR));
	while (get_next_line(fd, &line))
	{
		if (!ft_strncmp("R", line, 1))
			game->valid.render_size += is_valid_map_size_info(line);
		else if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) 
					|| !ft_strncmp("WE", line, 2) || !ft_strncmp("EA", line, 2) || !ft_strncmp("S", line, 1))
			check_valid_texture_info(line, game);
//		else if (!ft_strncmp("F", line, 1) || !ft_strncmp("C", line, 1))
//			get_floor_and_celing_color(game, line);
//		else if (ft_strlen(line))
//		{
//			get_map_grid(game, line);
//			game->item_count += count_item(line);
//		}
		else
			free(line);
	}
	close(fd);
	res = is_all_valid_factor(game);
	if (res == FALSE)
		error(FILE_ERROR);
	printf("res %d\n", res);
	return (res);
}

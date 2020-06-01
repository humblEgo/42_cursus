/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 00:25:41 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/01 15:50:09 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"

int	write_bmp_header(int fd, int file_size, t_game *game)
{
	char	bmp_header[54];
	int		res;

	ft_bzero(bmp_header, 54);
	ft_memcpy(bmp_header, "BM", sizeof(char) * 2);
	ft_memcpy(bmp_header + 2, &file_size, sizeof(int));
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	ft_memcpy(bmp_header + 18, &game->screen_w, sizeof(int));
	ft_memcpy(bmp_header + 22, &game->screen_h, sizeof(int));
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)24;
	res = write(fd, bmp_header, 54);
	return (res);
}

int	get_color(t_img *screen, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int *)(screen->data + (4 * screen->width * (screen->height - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int	write_bmp_data(int fd, t_game *game, t_img *screen)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;
	int					pad;

	pad = (4 - (game->screen_w * 3 % 4)) % 4;
	i = -1;
	while (++i < game->screen_h)
	{
		j = -1;
		while (++j < game->screen_w)
		{
			color = get_color(screen, i, j);
			if (write(fd, &color, 3) < 0)
				return (FALSE);
			if (pad > 0 && write(fd, &zero, pad) < 0)
				return (FALSE);
		}
	}
	return (TRUE);
}

int	save_bmp(t_game *game, t_img *screen)
{
	int	fd;
	int	file_size;
	int	bmp_file_header_size;
	int	bmp_info_header_size;
	int	bmp_pixel_data_size;

	//TODO: segfault 잡기, max screen_w, h config
	game->save_option = FALSE;
	bmp_file_header_size = 14;
	bmp_info_header_size = 40;
	bmp_pixel_data_size = 4 * game->screen_w * game->screen_h;
	file_size = bmp_file_header_size + bmp_info_header_size + bmp_pixel_data_size;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 777)) < 0)
		return (error(SAVE_FILE_ERROR));
	if (!(write_bmp_header(fd, file_size, game)))
		return (error(SAVE_FILE_ERROR));
	if (!(write_bmp_data(fd, game, screen)))
		return (error(SAVE_FILE_ERROR));
//	if (!(write(fd, screen->data, bmp_pixel_data_size)))
//		return (error(SAVE_FILE_ERROR));
	close(fd);
	return (TRUE);
}

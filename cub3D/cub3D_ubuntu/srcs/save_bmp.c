/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 00:25:41 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 03:41:33 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"

int	write_bmp_header(int fd, int file_size, t_game *game)
{
	char	bmp_header[54];
	int		res;
	int		height;

	ft_bzero(bmp_header, 54);
	ft_memcpy(bmp_header, "BM", sizeof(char) * 2);
	ft_memcpy(bmp_header + 2, &file_size, sizeof(int));
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	ft_memcpy(bmp_header + 18, &game->screen_w, sizeof(int));
	ft_memcpy(bmp_header + 22, &game->screen_h, sizeof(int));
	height = -game->screen_h;
	bmp_header[18] = (unsigned char)(game->screen_w);
	bmp_header[22] = (unsigned char)(height);
	bmp_header[23] = (unsigned char)(height >> 8);
	bmp_header[25] = (unsigned char)(height >> 16);
	bmp_header[24] = (unsigned char)(height >> 24);
	bmp_header[26] = (unsigned char)(1);
	bmp_header[28] = (unsigned char)(32);
	res = write(fd, bmp_header, 54);
	return (res);
}

unsigned char	get_color(t_game *game, t_img *screen, int x, int y)
{
	unsigned char	rgb;
	int				color;

	color = screen->data[y * game->screen_h + x];
	if (x % 4 == 1 && (color & 0xFF0000))
		rgb = (unsigned char)(color >> 4);
	else if (x % 4 == 2 && (color & 0x00FF00))
		rgb = (unsigned char)(color >> 2);
	else if (x % 4 == 3 && (color & 0x0000FF))
		rgb = (unsigned char)(color);
	return (rgb);
}

int	save_bmp(t_game *game, t_img *screen)
{
	int	fd;
	int	file_size;
	int	bmp_file_header_size;
	int	bmp_info_header_size;
	int	bmp_pixel_data_size;

	game->save_option = FALSE;
	bmp_file_header_size = 14;
	bmp_info_header_size = 40;
	bmp_pixel_data_size = 4 * game->screen_w * game->screen_h;
	file_size = bmp_file_header_size + bmp_info_header_size + bmp_pixel_data_size;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
		return (error(SAVING_FILE_ERROR));
	if (!(write_bmp_header(fd, file_size, game)))
		return (error(SAVING_FILE_ERROR));
	if (!(write(fd, screen->data, (game->screen_w * game->screen_h * 4))))
		return (error(SAVING_FILE_ERROR));
	close(fd);
	return (TRUE);
}

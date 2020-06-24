/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 00:25:41 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 13:49:37 by iwoo             ###   ########.fr       */
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

int	save_bmp(t_game *game, t_img *screen)
{
	int	fd;
	int	file_size;
	int	file_header_size;
	int	info_header_size;
	int	pixel_data_size;

	game->save_option = FALSE;
	file_header_size = 14;
	info_header_size = 40;
	pixel_data_size = 4 * game->screen_w * game->screen_h;
	file_size = file_header_size + info_header_size + pixel_data_size;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
		return (error(SAVING_FILE_ERROR));
	if (!(write_bmp_header(fd, file_size, game)))
		return (error(SAVING_FILE_ERROR));
	if (!(write(fd, screen->data, (game->screen_w * game->screen_h * 4))))
		return (error(SAVING_FILE_ERROR));
	close(fd);
	return (TRUE);
}

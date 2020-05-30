/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_item_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:50:35 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/30 21:47:13 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"
#include "libft.h"

void	sort_item_by_distance(t_game *game, t_item *item)
{
	int		i;
	int		j;
	t_item	temp;

	i = 0;
	while (i < game->item_count)
	{
		j = 0;
		while (j < game->item_count - 1)
		{
			if (item[j].dist < item[j + 1].dist)
			{
				ft_memmove(&temp, &item[j + 1], sizeof(t_item));
				ft_memmove(&item[j + 1], &item[j], sizeof(t_item));
				ft_memmove(&item[j], &temp, sizeof(t_item));
			}
			j++; }
		i++;
	} }

void	set_item_distance(t_game *game, t_item *item)
{
	t_player	*player;
	int			i;

	player = &game->player;
	i = -1;
	while (++i < game->item_count)
	{
		item[i].dist = (player->pos_x - item[i].x) * (player->pos_x - item[i].x) + 
			((player->pos_y - item[i].y) * (player->pos_y - item[i].y));
	}
}

void	calculate_render_item_info(t_game *game, t_item *item, t_rend_item *rd_item)
{
	t_player	*player;

	player = &game->player;
	rd_item->x = item->x - player->pos_x + 0.5;
	rd_item->y = item->y - player->pos_y + 0.5;
	rd_item->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
	rd_item->transform_x = rd_item->inv_det * (player->dir_y * rd_item->x - player->dir_x * rd_item->y);
	rd_item->transform_y = rd_item->inv_det * (-player->plane_y * rd_item->x + player->plane_x * rd_item->y);
	rd_item->screen_x = (int)((game->screen_w / 2) * (1 + rd_item->transform_x / rd_item->transform_y));
	rd_item->height = abs((int)(game->screen_h / rd_item->transform_y));
	rd_item->draw_start_y = -rd_item->height / 2 + game->screen_h / 2;
	if (rd_item->draw_start_y < 0)
		rd_item->draw_start_y = 0;
	rd_item->draw_end_y = rd_item->height / 2 + game->screen_h / 2;
	if (rd_item->draw_end_y >= game->screen_h)
		rd_item->draw_end_y = game->screen_h - 1;
	rd_item->width = abs((int)(game->screen_h / rd_item->transform_y));
	rd_item->draw_start_x = -rd_item->width / 2 + rd_item->screen_x;
	if (rd_item->draw_start_x < 0)
		rd_item->draw_start_x = 0;
	rd_item->draw_end_x = rd_item->width / 2 + rd_item->screen_x;
	if (rd_item->draw_end_x >= game->screen_w)
		rd_item->draw_end_x = game->screen_w - 1;
}

void	fill_item_image_color(t_game *game, t_rend_item *rd_item, t_img img_item, t_img *screen)
{
	int		x;
	int		y;
	int		tmp;

	x = rd_item->draw_start_x - 1;
	while (++x < rd_item->draw_end_x)
	{
		img_item.tex_x = (int)(256 * (x - (-rd_item->width / 2 + rd_item->screen_x)) 
				* img_item.width / rd_item->width) / 256;
		if (rd_item->transform_y > 0 && x > 0 && x < game->screen_w && 
				rd_item->transform_y < game->zbuffer[x]) 
		{
			y = rd_item->draw_start_y - 1;
			while (++y < rd_item->draw_end_y)
			{
				tmp = y * 256 - game->screen_h * 128 + rd_item->height * 128;
				img_item.tex_y = ((tmp * img_item.height) / rd_item->height) / 256;
				img_item.color = img_item.data[img_item.width * img_item.tex_y + img_item.tex_x];
				if ((img_item.color & 0x00FFFFFF) != 0)
					screen->data[y * game->screen_w + x] = img_item.color;
			}
		}
	}
}

void	fill_item_image(t_game *game, t_img *screen)
{
	int			i;
	t_rend_item	rd_item;
	t_item		*item;
	t_img		img_item;

	item = game->item;
	img_item = game->texture[4];
	set_item_distance(game, item);
	sort_item_by_distance(game, item);
	i = -1;
	while (++i < game->item_count)
	{
		calculate_render_item_info(game, &item[i], &rd_item);
		fill_item_image_color(game, &rd_item, img_item, screen);
	}
	//TODO: 벽뚫는 아이템 해결!
}

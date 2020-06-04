/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_item_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:50:35 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/03 14:25:11 by iwoo             ###   ########.fr       */
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
			j++;
		}
		i++;
	}
}

void	set_item_distance(t_game *game, t_item *item)
{
	t_player	*player;
	int			i;

	player = &game->player;
	i = -1;
	while (++i < game->item_count)
	{
		item[i].dist = (player->pos_x - item[i].x)
			* (player->pos_x - item[i].x)
			+ ((player->pos_y - item[i].y) * (player->pos_y - item[i].y));
	}
}

void	calculate_rend_item(t_game *game, t_item *item, t_rend_item *rd_i)
{
	t_player	*p;

	p = &game->player;
	rd_i->x = item->x - p->pos_x + 0.5;
	rd_i->y = item->y - p->pos_y + 0.5;
	rd_i->inv_det = 1.0 / (p->plane_x * p->dir_y - p->dir_x * p->plane_y);
	rd_i->tf_x = rd_i->inv_det * (p->dir_y * rd_i->x - p->dir_x * rd_i->y);
	rd_i->tf_y = rd_i->inv_det * (-p->plane_y * rd_i->x + p->plane_x * rd_i->y);
	rd_i->screen_x = (int)((game->screen_w / 2)
			* (1 + rd_i->tf_x / rd_i->tf_y));
	rd_i->height = abs((int)(game->screen_h / rd_i->tf_y));
	rd_i->draw_start_y = -rd_i->height / 2 + game->screen_h / 2;
	if (rd_i->draw_start_y < 0)
		rd_i->draw_start_y = 0;
	rd_i->draw_end_y = rd_i->height / 2 + game->screen_h / 2;
	if (rd_i->draw_end_y >= game->screen_h)
		rd_i->draw_end_y = game->screen_h - 1;
	rd_i->width = abs((int)(game->screen_h / rd_i->tf_y));
	rd_i->draw_start_x = -rd_i->width / 2 + rd_i->screen_x;
	if (rd_i->draw_start_x < 0)
		rd_i->draw_start_x = 0;
	rd_i->draw_end_x = rd_i->width / 2 + rd_i->screen_x;
	if (rd_i->draw_end_x >= game->screen_w)
		rd_i->draw_end_x = game->screen_w - 1;
}

void	fill_item_color(t_game *game, t_rend_item *rd_i, t_img img, t_img *srn)
{
	int		x;
	int		y;
	int		tmp;

	x = rd_i->draw_start_x - 1;
	while (++x < rd_i->draw_end_x)
	{
		img.tex_x = (int)(256 * (x - (-rd_i->width / 2 + rd_i->screen_x))
				* img.width / rd_i->width) / 256;
		if (rd_i->tf_y > 0 && x > 0 && x < game->screen_w &&
				rd_i->tf_y < game->zbuffer[x])
		{
			y = rd_i->draw_start_y - 1;
			while (++y < rd_i->draw_end_y)
			{
				tmp = y * 256 - game->screen_h * 128 + rd_i->height * 128;
				img.tex_y = ((tmp * img.height) / rd_i->height) / 256;
				img.color = img.data[img.width
					* img.tex_y + img.tex_x];
				if ((img.color & 0x00FFFFFF) != 0)
					srn->data[y * game->screen_w + x] = img.color;
			}
		}
	}
}

void	fill_item_img(t_game *game, t_img *screen)
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
		calculate_rend_item(game, &item[i], &rd_item);
		fill_item_color(game, &rd_item, img_item, screen);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:41:27 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/10 23:32:52 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	init_line(char **line)
{
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	return (1);
}

int	init_buf_read(int fd, char *buf)
{
	int	read_nb;

	read_nb = 0;
	ft_memset(buf, '\0', BUFFER_SIZE + 1);
	if (((read_nb = read(fd, buf, BUFFER_SIZE)) < 0))
		return (-1);
	return (read_nb);
}

int	read_if_buf_empty(int fd, t_buf *buf)
{
	if (buf->buf[0] == '\0')
		if ((buf->read_nb = init_buf_read(fd, buf->buf)) < 0)
			return (-1);
	return (1);
}

int	is_last_line_eof(int fd, t_buf *buf)
{
	if ((buf->read_nb = init_buf_read(fd, buf->buf)) < 0)
		return (-1);
	buf->idx = 0;
	if (buf->buf[0] == '\0')
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_buf	buf[FILE_ERA];

	if (fd < 0 || fd > FILE_ERA || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (init_line(line) < 0 || read_if_buf_empty(fd, &buf[fd]) < 0)
		return (-1);
	while (buf[fd].read_nb != 0)
	{
		*line = ft_strjoin_bfnl(*line, &(buf[fd].buf[buf[fd].idx]));
		while (buf[fd].buf[buf[fd].idx] && buf[fd].buf[buf[fd].idx] != '\n')
			buf[fd].idx++;
		if (buf[fd].buf[buf[fd].idx] == '\0')
		{
			if ((buf[fd].res = is_last_line_eof(fd, &buf[fd])) < 1)
				return (buf[fd].res);
		}
		else
		{
			buf[fd].idx++;
			return (1);
		}
	}
	return (0);
}

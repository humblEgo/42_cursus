/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:41:27 by iwoo              #+#    #+#             */
/*  Updated: 2020/03/01 22:51:51 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	idx_read = 0;
	int			read_nb;
	int			idx_strt;
	static int	file[FILE_ERA];

	if (fd < 0 || line == NULL)
		return (-1);
	if (file[fd] == 0)
	{
		if(!(*line = malloc(sizeof(char))))
			return (-1);
		*line[0] = '\0';
		file[fd] = 1;
	}
	if (idx_read == 0)
		ft_memset(buf, '\0', BUFFER_SIZE + 1);
	else
	{
		*line = ft_strnjoin(*line, &buf[idx_read], BUFFER_SIZE - idx_read);
		ft_memset(buf, '\0', BUFFER_SIZE + 1);
		idx_read = 0;
	}
	if ((read_nb = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	idx_strt = idx_read;
	while (buf[idx_read] != '\n' && buf[idx_read])
		idx_read++;
	if (read_nb > 0)
	{
		if (idx_read == BUFFER_SIZE)
		{
			*line = ft_strnjoin(*line, &buf[idx_strt], idx_read);
			idx_read = 0;
			get_next_line(fd, line);
		}
		else
			*line = ft_strnjoin(*line, &buf[idx_strt], idx_read);
	}
	else
	{
		*line = ft_strnjoin(*line, &buf[idx_strt], idx_read);
	}
	return (1);
}

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
	static int	i = 0;
	static int	read_nb;
	static int	file[FILE_ERA];

	if (fd < 0 || line == NULL)
		return (-1);
	if(!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	if (buf[i] == '\n')
		i++;
	*line = ft_strjoin_bfnl(*line, &buf[i]);
	ft_memset(buf, '\0', BUFFER_SIZE + 1);
	i = 0;
	if ((read_nb = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	while (buf[i] && buf[i] != '\n')
	{
		if (i == BUFFER_SIZE - 1)
		{
			*line = ft_strjoin_bfnl(*line, buf);
			ft_memset(buf, '\0', BUFFER_SIZE + 1);
			if ((read_nb = read(fd, buf, BUFFER_SIZE)) < 0)
				return (-1);
			i = -1;
		}
		i++;
	}
	*line = ft_strjoin_bfnl(*line, buf);	
	if (ft_strlen(buf) != BUFFER_SIZE)
		return (0);
	return (read_nb ? 1 : 0);
}

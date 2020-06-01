/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:41:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/05/28 00:25:29 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_buf
{
	int		idx;
	int		read_nb;
	char	buf[BUFFER_SIZE];
	int		res;
}				t_buf;

/*
** get_next_line.c
*/

int				get_next_line(int fd, char **line);

/*
** get_next_line_util.c
*/

char			*ft_strjoin_bfnl(char *s1, char *s2);
void			*ft_memset(void *s, int c, size_t n);
int				ft_strlen_bfnl(char *str);

#endif

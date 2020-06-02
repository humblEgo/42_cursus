/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:41:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/02 16:31:02 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 2

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

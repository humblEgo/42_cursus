/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:41:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/03/03 23:54:59 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>   // I will delete it after complete

# define FILE_ERA 2048

int		get_next_line(int fd, char **line);

char	*ft_strdup(const char *buf);
char	*ft_strjoin_bfnl(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void	*s, int c, size_t n);
int		ft_strlen(char *str);
int		ft_strlen_bfnl(char *str);

#endif

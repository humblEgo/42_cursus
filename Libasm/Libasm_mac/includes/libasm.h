/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:53:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/09 13:00:52 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include	<unistd.h>
# include	<stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t nbytes);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
#endif

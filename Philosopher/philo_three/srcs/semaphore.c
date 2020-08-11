/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:27:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/11 14:38:21 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

sem_t	*ft_sem_open(char const *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

int		make_sem_name_in_buf(char *buf, char *src, int ph_num)
{
	int i;

	if (ft_strlen(src) > BUFFER_SIZE)
		return (FALSE);
	i = -1;
	while (src[++i])
		buf[i] = src[i];
	buf[i++] = ph_num + '0';
	buf[i] = '\0';
	return (TRUE);
}

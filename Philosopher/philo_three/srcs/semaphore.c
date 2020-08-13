/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:27:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/13 01:22:08 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

sem_t	*ft_sem_open(char *name, int value)
{
	sem_t *res;

	sem_unlink(name);
	if ((res = sem_open(name, O_CREAT | O_EXCL, 0644, value)) == SEM_FAILED)
		return (NULL);
	return (res);
}

int		make_sem_name_in_buf(char *buf, char *src, int ph_num)
{
	int i;

	memset((void *)buf, 0, BUFFER_SIZE);
	if (ft_strlen(src) > BUFFER_SIZE)
		return (FALSE);
	i = -1;
	while (src[++i])
		buf[i] = src[i];
	while (ph_num > 0)
	{
		buf[i++] = (ph_num % 10) + '0';
		ph_num /= 10;
	}
	buf[i] = '\0';
	return (TRUE);
}

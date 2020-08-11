/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_detached_thread.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:07:48 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/11 14:38:21 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	create_detached_thread(pthread_t *tid, void *func, void *arg, int arg_type)
{
	if (arg_type == PH)
	{
		if (pthread_create(tid, NULL, func, (t_ph *)arg))
			return (FALSE);
	}
	else if (arg_type == PH_INFO)
	{
		if (pthread_create(tid, NULL, func, (t_ph_info *)arg))
			return (FALSE);
	}
	else
		return (error("Invalid arg_type\n"));
	pthread_detach(*tid);
	return (TRUE);
}
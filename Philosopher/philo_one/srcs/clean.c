/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:58:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/06 15:58:23 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void ft_free(void *ptr)
{
	if (!ptr)
		return;
	free(ptr);
}

void destroy_mutexes(t_ph_info *ph_info)
{
	int i;

	if (ph_info->ph)
	{
		i = -1;
		while (++i < ph_info->cond->num_of_ph)
		{
			pthread_mutex_destroy(&ph_info->ph[i].last_eat_time_m);
			pthread_mutex_destroy(&ph_info->ph[i].eating_m);
			pthread_mutex_destroy(&ph_info->ph[i].must_eat_m);
		}
	}
	if (ph_info->forks)
	{
		i = -1;
		while (++i < ph_info->cond->num_of_ph)
			pthread_mutex_destroy(&ph_info->forks[i].fork_m);
	}
	pthread_mutex_destroy(&ph_info->msg_m);
	pthread_mutex_destroy(&ph_info->finish_dining_m);
}

int clean_ph_info(t_ph_info *ph_info)
{
	destroy_mutexes(ph_info);
	ft_free(ph_info->cond);
	ft_free(ph_info->ph);
	ft_free(ph_info->forks);
	ph_info->cond = NULL;
	ph_info->ph = NULL;
	ph_info->forks = NULL;
	ph_info = NULL;
	return (0);
}
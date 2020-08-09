/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:23:21 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/09 17:23:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	destroy_m_forks(t_fork *forks, int n_of_ph)
{
	int i;

	i = -1;
	while (++i < n_of_ph)
		pthread_mutex_destroy(&forks[i].fork_m);
}

static void	destroy_m_ph_info(t_ph_info *ph_info)
{
	pthread_mutex_destroy(&ph_info->msg_m);
	pthread_mutex_destroy(&ph_info->finish_dining_m);
	pthread_mutex_destroy(&ph_info->ensure_unlock_m);
}

static void	destroy_m_ph(t_ph *ph, int n_of_ph)
{
	int i;

	i = -1;
	while (++i < n_of_ph)
	{
		pthread_mutex_destroy(&ph[i].last_eat_time_m);
		pthread_mutex_destroy(&ph[i].eating_m);
		pthread_mutex_destroy(&ph[i].must_eat_m);
		pthread_mutex_destroy(&ph[i].ensure_ph_unlock_m);
	}
}

static void	destroy_m_monitor(t_ph *ph, int n_of_monitor)
{
	int i;

	i = -1;
	while (++i < n_of_monitor)
	{
		pthread_mutex_destroy(&ph[i].ensure_monitor_unlock_m);
	}
}

void		destroy_m_all(t_ph_info *ph_info, int n_of_ph, int n_of_monitor)
{
	if (ph_info->ph)
	{
		destroy_m_ph(ph_info->ph, n_of_ph);
		destroy_m_monitor(ph_info->ph, n_of_monitor);
	}
	if (ph_info->forks)
		destroy_m_forks(ph_info->forks, n_of_ph);
	destroy_m_ph_info(ph_info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensure_mutexes_unlocked.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:26:45 by humblego          #+#    #+#             */
/*   Updated: 2020/08/09 00:51:42 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ensure_unlock(t_ph *ph)
{
	pthread_mutex_lock(ph->ensure_unlock_m);
	if (*ph->is_all_unlocked)
	{
		pthread_mutex_unlock(ph->ensure_unlock_m);
		pthread_mutex_unlock(&ph->ensure_ph_unlock_m);
		while (1)
			usleep(42424242);
	}
	pthread_mutex_unlock(ph->ensure_unlock_m);
}

void	ensure_unlock_before_eating(t_ph *ph)
{
	pthread_mutex_lock(ph->ensure_unlock_m);
	if (*ph->is_all_unlocked)
	{
		pthread_mutex_unlock(ph->ensure_unlock_m);
		pthread_mutex_unlock(&ph->left_fork->fork_m);
		pthread_mutex_unlock(&ph->right_fork->fork_m);
		pthread_mutex_unlock(&ph->ensure_ph_unlock_m);
		while (1)
			usleep(42424242);
	}
	pthread_mutex_unlock(ph->ensure_unlock_m);
}

void	ensure_monitor_unlock(t_ph *ph)
{
	pthread_mutex_lock(ph->ensure_unlock_m);
	if (*ph->is_all_unlocked)
	{
		pthread_mutex_unlock(ph->ensure_unlock_m);
		pthread_mutex_unlock(&ph->ensure_monitor_unlock_m);
		while (1)
			usleep(4242424242);
	}
	pthread_mutex_unlock(ph->ensure_unlock_m);
}

void    wait_all_m_unlocked(t_ph_info *ph_info, int n_of_ph, int n_of_monitor)
{
    int i;

	pthread_mutex_lock(&ph_info->ensure_unlock_m);
	ph_info->is_all_unlocked = TRUE;
	pthread_mutex_unlock(&ph_info->ensure_unlock_m);
    i = -1;
	while (++i < n_of_monitor)
	{
		pthread_mutex_lock(&ph_info->ph[i].ensure_monitor_unlock_m);
		pthread_mutex_unlock(&ph_info->ph[i].ensure_monitor_unlock_m);
	}
	i = -1;
	while (++i < n_of_ph)
	{
		pthread_mutex_lock(&ph_info->ph[i].ensure_ph_unlock_m);
		pthread_mutex_unlock(&ph_info->ph[i].ensure_ph_unlock_m);
	}
}

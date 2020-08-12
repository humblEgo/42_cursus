/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensure_mutexes_unlocked.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:26:45 by humblego          #+#    #+#             */
/*   Updated: 2020/08/12 10:10:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		unlock_m_if_done(t_ph *ph, int flag)
{
	pthread_mutex_lock(ph->ensure_unlock_m);
	if (*ph->let_all_m_unlock)
	{
		pthread_mutex_unlock(ph->ensure_unlock_m);
		if (flag == FORK_M_LOCKED)
		{
			pthread_mutex_unlock(&ph->left_fork->fork_m);
			pthread_mutex_unlock(&ph->right_fork->fork_m);
		}
		if (flag == MONITOR)
			pthread_mutex_unlock(&ph->ensure_monitor_unlock_m);
		else if (flag != MONITOR_EAT_COUNT)
			pthread_mutex_unlock(&ph->ensure_ph_unlock_m);
		return (TRUE);
	}
	pthread_mutex_unlock(ph->ensure_unlock_m);
	return (FALSE);
}

void	wait_all_m_unlocked(t_ph_info *ph_info, int n_of_ph, int n_of_monitor)
{
	int i;

	pthread_mutex_lock(&ph_info->ensure_unlock_m);
	ph_info->let_all_m_unlock = TRUE;
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

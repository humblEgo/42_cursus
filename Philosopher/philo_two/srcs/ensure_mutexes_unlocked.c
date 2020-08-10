/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensure_mutexes_unlocked.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:26:45 by humblego          #+#    #+#             */
/*   Updated: 2020/08/10 17:14:41 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

// void	wait_if_done(t_ph *ph, int flag)
// {
// 	sem_wait(ph->done_s);
// 	if (*ph->let_wait_if_done)
// 	{
// 		while (1)
// 			usleep(42424242);
// 	}
// 	sem_post(ph->done_s);
// }

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

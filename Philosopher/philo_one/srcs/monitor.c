/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:03:03 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/12 10:12:10 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	monitor_ph(t_ph *ph)
{
	while (1)
	{
		if (unlock_m_if_done(ph, MONITOR))
			return ;
		pthread_mutex_lock(&ph->eating_m);
		if (get_cur_time() > ph->last_eat_time + ph->cond->time_to_die)
		{
			print_ph_state(ph, DIED);
			pthread_mutex_unlock(&ph->eating_m);
			pthread_mutex_unlock(&ph->ensure_ph_unlock_m);
			pthread_mutex_unlock(&ph->ensure_monitor_unlock_m);
			pthread_mutex_unlock(ph->finish_dining_m);
			return ;
		}
		pthread_mutex_unlock(&ph->eating_m);
		usleep(1000);
	}
}

void	monitor_eat_count(t_ph_info *ph_info)
{
	t_ph	*ph;
	int		i;

	ph = ph_info->ph;
	if (ph_info->cond->count_must_eat > 0)
	{
		i = -1;
		while (++i < ph->cond->num_of_ph)
		{
			if (unlock_m_if_done(&ph[i], MONITOR_EAT_COUNT))
				return ;
			pthread_mutex_lock(&ph[i].must_eat_m);
			pthread_mutex_unlock(&ph[i].must_eat_m);
			usleep(1000);
		}
	}
	else if (ph_info->cond->count_must_eat == 0)
		pthread_mutex_unlock(&ph->ensure_ph_unlock_m);
	print_ph_state(ph, MUST_EAT_REACHED);
	pthread_mutex_unlock(ph->finish_dining_m);
}

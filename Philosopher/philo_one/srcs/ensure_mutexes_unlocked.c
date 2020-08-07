#include "philo_one.h"

void	ensure_unlock(t_ph *ph)
{
	pthread_mutex_lock(ph->ensure_unlock_m);
	if (*ph->is_all_unlocked)
	{
		pthread_mutex_unlock(ph->ensure_unlock_m);
		pthread_mutex_unlock(&ph->ensure_ph_unlock_m);
		while (1)
		{
			printf("%d thread mutexes all unlocked!\n", ph->ph_num);
			usleep(2147483646);
		}
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
		{
			printf("%d monitor mutexes all unlocked!\n", ph->ph_num);
			usleep(2147483646);
		}
	}
	pthread_mutex_unlock(ph->ensure_unlock_m);
}

void    wait_all_mutexes_unlocked(t_ph_info *ph_info)
{
    int i;

	pthread_mutex_lock(&ph_info->ensure_unlock_m);
	ph_info->is_all_unlocked = TRUE;
	pthread_mutex_unlock(&ph_info->ensure_unlock_m);
    i = -1;
	while (++i < ph_info->cond->num_of_ph)
	{
		pthread_mutex_lock(&ph_info->ph[i].ensure_ph_unlock_m);
		pthread_mutex_unlock(&ph_info->ph[i].ensure_ph_unlock_m);
		pthread_mutex_lock(&ph_info->ph[i].ensure_monitor_unlock_m);
		pthread_mutex_unlock(&ph_info->ph[i].ensure_monitor_unlock_m);
	}
}


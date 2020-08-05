#include "philo_one.h"

void    monitor_ph(t_ph *ph)
{
	while (1)
	{
		pthread_mutex_lock(&ph->eating_m);
		if (ph->is_eating_now == TRUE)
		{
			pthread_mutex_unlock(&ph->eating_m);
			continue ;
		}
		pthread_mutex_unlock(&ph->eating_m);
		pthread_mutex_lock(&ph->last_eat_time_m);
		if (get_cur_time() > ph->last_eat_time + ph->cond->time_to_die)
		{
			print_state(ph, DIED);
			pthread_mutex_unlock(&ph->last_eat_time_m);
			pthread_mutex_unlock(ph->finish_dining_m);
			return ;
		}
		pthread_mutex_unlock(&ph->last_eat_time_m);
		usleep(10 * 1000);
	}
}

void	monitor_eat_count(t_ph_info *ph_info)
{
	t_ph	*ph;
	int		i;

	ph = ph_info->ph;
	i = -1;
	while (++i < ph->cond->num_of_ph)
	{
		pthread_mutex_lock(&ph[i].must_eat);
		pthread_mutex_unlock(&ph[i].must_eat);
	}
	print_ate_enough(ph_info);
	pthread_mutex_unlock(ph->finish_dining_m);
}
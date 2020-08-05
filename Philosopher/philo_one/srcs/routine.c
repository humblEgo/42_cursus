#include "philo_one.h"

void    pick_up_fork(t_ph *ph, t_fork *fork)
{
	pthread_mutex_lock(&fork->fork_m);
	print_state(ph, PICKING_FORK);
}

int     eating(t_ph *ph)
{
	pthread_mutex_lock(&ph->eating_m);
	ph->is_eating_now = TRUE;
	ph->last_eat_time = get_cur_time();
	print_state(ph, EATING);
	usleep(ph->cond->time_to_eat * 1000);
	ph->is_eating_now = FALSE;
	ph->num_of_meals++;
	pthread_mutex_unlock(&ph->eating_m);
	if (ph->num_of_meals == ph->cond->count_must_eat)
	{
		// write(1, "woo\n", 4);
		pthread_mutex_unlock(&ph->must_eat);
	}
	return (TRUE);
}

int     putting_down_forks(t_ph *ph)
{
	if (ph->ph_num % 2 == 0)
	{
		pthread_mutex_unlock(&ph->left_fork->fork_m);
		pthread_mutex_unlock(&ph->right_fork->fork_m);
	}
	else
	{
		pthread_mutex_unlock(&ph->right_fork->fork_m);
		pthread_mutex_unlock(&ph->left_fork->fork_m);
	}
	return (TRUE);
}

int     picking_up_forks(t_ph *ph)
{
	if (ph->ph_num % 2 == 0)
	{
		pick_up_fork(ph, ph->left_fork);
		pick_up_fork(ph, ph->right_fork);
	}
	else
	{
		pick_up_fork(ph, ph->right_fork);
		pick_up_fork(ph, ph->left_fork);
	}
	return (TRUE);
}

int     sleeping(t_ph *ph)
{
	print_state(ph, SLEEPING);
	usleep(ph->cond->time_to_sleep * 1000);
	return (TRUE);
}

int     thinking(t_ph *ph)
{
	print_state(ph, THINKING);
	return (TRUE);
}
void    ph_routine(void *ph_void)
{
	t_ph        *ph;
	pthread_t   tid;

	ph = (t_ph *)ph_void;
	ph->last_eat_time = get_cur_time();
	if (pthread_create(&tid, NULL, (void *)monitor_ph, ph))
	{
		ft_putstr_fd("error: failed to create thread\n", 2);
		return ;
	}
	pthread_detach(tid);
	while (1)
	{
		picking_up_forks(ph);
		eating(ph);
		putting_down_forks(ph);
		sleeping(ph);
		thinking(ph);
	}
}
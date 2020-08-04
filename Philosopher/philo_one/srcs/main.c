#include "philo_one.h"

int is_valid_arg(char **argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if (!(is_num_str(argv[i])))
			return (FALSE);
	}
	return (TRUE);
}

void    pick_up_fork(t_ph *ph, t_fork *fork)
{
	pthread_mutex_lock(&fork->fork_m);
	print_status(ph, PICKING_FORK);
}

int     eating(t_ph *ph)
{
	pthread_mutex_lock(&ph->mutex);
	ph->is_eating_now = TRUE;
	ph->last_eat_time = get_cur_time();
	print_status(ph, EATING);
	usleep(ph->cond->time_to_eat);
	ph->is_eating_now = FALSE;
	pthread_mutex_unlock(&ph->mutex);
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
	print_status(ph, SLEEPING);
	usleep(ph->cond->time_to_sleep);
	return (TRUE);
}

int     thinking(t_ph *ph)
{
	print_status(ph, THINKING);
	return (TRUE);
}

void    monitor_ph(t_ph *ph)
{
	int cur;

	while (1)
	{
		pthread_mutex_lock(&ph->mutex);
		cur = get_cur_time();
		if (cur > ph->last_eat_time + ph->cond->time_to_die)
		{
			printf("cur: %d last_eat_time: %d time_to_die: %d\n", cur, ph->last_eat_time, ph->cond->time_to_die);
			print_status(ph, DIED);
			pthread_mutex_unlock(&ph->mutex);
			pthread_mutex_unlock(ph->someone_died_m);
			return ;
		}
		pthread_mutex_unlock(&ph->mutex);
		usleep(10);
	}
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

int     dining_start(t_ph_info *ph_info)
{
	t_ph        *ph;
	t_cond      *cond;
	int         i;

	ph = ph_info->ph;
	cond = ph_info->cond;
	i = -1;
	while (++i < cond->num_of_ph)
	{
		if(pthread_create(&(ph[i].thread), NULL, (void *)ph_routine, &ph[i]) != 0)
		{
			ft_putstr_fd("error: failed to create thread\n", 2);
			return (FALSE);
		}
		pthread_detach(ph[i].thread);
	}
	return (TRUE);
}

int main(int argc, char *argv[])
{
	t_ph_info ph_info;

	if (argc < 5 || argc > 6)
		return (0);
	if (is_valid_arg(&argv[1]))
	{
		init_ph_info(&ph_info, argc, &argv[1]);
		dining_start(&ph_info);
	}
	pthread_mutex_lock(&ph_info.someone_died_m);
	pthread_mutex_unlock(&ph_info.someone_died_m);
	printf("The end\n");
	//TODO: free all
	return (0);
}
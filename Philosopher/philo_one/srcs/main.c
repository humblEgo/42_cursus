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

void    *routine_ph(void *ph_void)
{
	t_ph        *ph;

	ph = (t_ph *)ph_void;
	while (1)
	{
		picking_up_forks(ph);
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return ((void *)TRUE);
}

int     dining_start(t_ph_info *ph_info)
{
	t_ph        *ph;
	pthread_t	tid;
	int         i;

	ph = ph_info->ph;
	if (ph->cond->count_must_eat >= 0)
		if (!create_detached_thread(&tid, monitor_eat_count, ph_info, PH_INFO))
			return (error(CREATE_THREAD));
	i = -1;
	while (++i < ph_info->cond->num_of_ph)
	{
		ph[i].last_eat_time = get_cur_time();
		if (!create_detached_thread(&tid, monitor_ph, &ph[i], PH))
			return (error(CREATE_THREAD));
		if (!create_detached_thread(&tid, routine_ph, &ph[i], PH))
			return (error(CREATE_THREAD));
        usleep(100);
	}
	return (TRUE);
}

int main(int argc, char *argv[])
{
	t_ph_info ph_info;

	if (argc < 5 || argc > 6)
		return (0);
	if (!is_valid_arg(&argv[1]))
		return (0);
	if (!init_ph_info(&ph_info, argc, &argv[1]))
		return (error(INIT) + clean_ph_info(&ph_info));
	if (!dining_start(&ph_info))
		return (error(DINING) + clean_ph_info(&ph_info));
	pthread_mutex_lock(&ph_info.finish_dining_m);
	pthread_mutex_unlock(&ph_info.finish_dining_m);
	clean_ph_info(&ph_info);
	return (0);
}
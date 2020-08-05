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

int     dining_start(t_ph_info *ph_info)
{
	t_ph        *ph;
	t_cond      *cond;
	pthread_t	tid;
	int         i;

	ph = ph_info->ph;
	cond = ph_info->cond;
	if (ph->cond->count_must_eat >= 0)
	{
		if (pthread_create(&tid, NULL, (void *)monitor_eat_count, ph_info))
			return (FALSE);
		pthread_detach(tid);
	}
	i = -1;
	while (++i < cond->num_of_ph)
	{
		if (pthread_create(&tid, NULL, (void *)ph_routine, &ph[i]) != 0)
			return (FALSE);
		pthread_detach(tid);
        usleep(100);
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
	pthread_mutex_lock(&ph_info.finish_dining_m);
	pthread_mutex_unlock(&ph_info.finish_dining_m);
	//TODO: free all
	return (0);
}
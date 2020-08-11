/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:04:36 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/10 20:08:18 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		is_valid_arg(char **argv)
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

void	*routine_ph(void *ph_void)
{
	t_ph *ph;

	ph = (t_ph *)ph_void;
	while (1)
	{
		picking_up_forks(ph);
		eating(ph);
		put_down_forks(ph);
		sleeping(ph);
		thinking(ph);
	}
	return ((void *)TRUE);
}

int		dining_start(t_ph_info *ph_info)
{
	t_ph		*ph;
	pthread_t	tid;
	int			i;

	ph = ph_info->ph;
	if (ph->cond->count_must_eat >= 0)
		if (!create_detached_thread(&tid, monitor_eat_count, ph_info, PH_INFO))
			return (error(CREATE_THREAD) + CREATE_MONITOR_EC_ERRNO);
	i = -1;
	while (++i < ph_info->cond->num_of_ph)
	{
		if ((ph[i].last_eat_time = get_cur_time()) < 0)
			return (error(GET_TIME) + GET_TIME_ERRNO + i);
		if (!create_detached_thread(&tid, monitor_ph, &ph[i], PH))
			return (error(CREATE_THREAD) + CREATE_MONITOR_PH_ERRNO + i);
		if (!create_detached_thread(&tid, routine_ph, &ph[i], PH))
			return (error(CREATE_THREAD) + CREATE_ROUTINE_PH_ERRNO + i);
		usleep(5);
	}
	return (TRUE);
}

void	wait_finish_dining(t_ph_info *ph_info)
{
	sem_wait(ph_info->finish_dining_s);
	sem_post(ph_info->finish_dining_s);
}

int		main(int argc, char *argv[])
{
	t_ph_info	ph_info;
	int			error_num;

	if (argc < 5 || argc > 6)
		return (error(INVALID_ARG));
	if (!is_valid_arg(&argv[1]))
		return (error(INVALID_ARG));
	if ((error_num = init_ph_info(&ph_info, argc, &argv[1])) != TRUE)
		return (error(INIT) + clean_all(&ph_info, error_num));
	if ((error_num = dining_start(&ph_info)) != TRUE)
		return (error(DINING) + clean_all(&ph_info, error_num));
	wait_finish_dining(&ph_info);
	clean_all(&ph_info, NO_ERROR);
	return (0);
}
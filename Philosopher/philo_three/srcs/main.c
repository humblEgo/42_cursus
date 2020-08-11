/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:04:36 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/11 17:48:22 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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

void	clean_if_end(t_ph *ph)
{
	if (sem_wait(ph->clean_all_s) != 0)
	{
		ft_putstr_fd("============>end: ", 1);
		ft_putnbr_fd(ph->ph_num, 1);
		ft_free(ph->cond);
		ph->cond = NULL;
		ft_free(ph);
		ph = NULL;
		sem_post(ph->clean_all_s);
		while (1)
		{
			ft_putstr_fd("============>end: ", 1);
			ft_putnbr_fd(ph->ph_num, 1);
			sleep(10);
		}
	}
	sem_post(ph->clean_all_s);
}

void	*routine_ph(void *ph_void)
{
	t_ph *ph;

	ph = (t_ph *)ph_void;
	while (1)
	{
		clean_if_end(ph);
		picking_up_forks(ph);
		clean_if_end(ph);
		eating(ph);
		clean_if_end(ph);
		put_down_forks(ph);
		clean_if_end(ph);
		sleeping(ph);
		clean_if_end(ph);
		thinking(ph);
	}
	return ((void *)TRUE);
}

void	wait_finish_dining(t_ph_info *ph_info)
{
	sem_wait(ph_info->finish_dining_s);
	sem_post(ph_info->finish_dining_s);
}
#include <stdio.h>
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
		ph_info->ph[i].pid = fork();
		if (ph_info->ph[i].pid < 0)
			return (FALSE);
		else if (ph_info->ph[i].pid == 0)
		{
			if ((ph[i].last_eat_time = get_cur_time()) < 0)
				return (error(GET_TIME) + GET_TIME_ERRNO + i);
			if (!create_detached_thread(&tid, monitor_ph, &ph[i], PH))
				return (error(CREATE_THREAD) + CREATE_MONITOR_PH_ERRNO + i);
			routine_ph((void *)&ph_info->ph[i]);
		}
	}
	return (TRUE);
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

	sem_close(ph_info.clean_all_s);
	sem_unlink(CLEAN_ALL_S);
	// sem_wait(ph_info.clean_all_s);
	// ph_info.is_end = TRUE;
	// sem_post(ph_info.clean_all_s);
	sleep(10);
	int i;

	i = -1;
	while (++i < ph_info.cond->num_of_ph)
		kill(ph_info.ph[i].pid, SIGQUIT);
	clean_all(&ph_info, NO_ERROR);
	//TODO: memory leaks
	while (1)
		;
	return (0);
}

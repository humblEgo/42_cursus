/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ph_and_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:11:41 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/11 14:21:25 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		make_ph_and_monitor(t_ph_info *ph_info, int i)
{
	t_ph		*ph;
	pthread_t	tid;

	ph = ph_info->ph;
	if ((ph[i].last_eat_time = get_cur_time()) < 0)
		return (error(GET_TIME) + GET_TIME_ERRNO + i);
	if (!create_detached_thread(&tid, monitor_ph, &ph[i], PH))
		return (error(CREATE_THREAD) + CREATE_MONITOR_PH_ERRNO + i);
	if (!create_detached_thread(&tid, routine_ph, &ph[i], PH))
		return (error(CREATE_THREAD) + CREATE_ROUTINE_PH_ERRNO + i);
	return (TRUE);
}

int		make_even_ph_and_monitor(t_ph_info *ph_info)
{
	int i;
	int	err_num;

	i = -1;
	while (++i < ph_info->cond->num_of_ph)
	{
		if (i % 2 == 0)
			if ((err_num = make_ph_and_monitor(ph_info, i)) != TRUE)
				return (err_num);
		usleep(100);
	}
	return (TRUE);
}

int		make_odd_ph_and_monitor(t_ph_info *ph_info)
{
	int i;
	int	err_num;

	i = -1;
	while (++i < ph_info->cond->num_of_ph)
	{
		if (i % 2 == 1)
			if ((err_num = make_ph_and_monitor(ph_info, i)) != TRUE)
				return (err_num);
		usleep(100);
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:03:03 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/12 14:27:24 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	monitor_ph(t_ph *ph)
{
	while (1)
	{
		sem_wait(ph->eating_s);
		if (get_cur_time() > ph->last_eat_time + ph->cond->time_to_die)
		{
			print_ph_state(ph, DIED);
			sem_post(ph->eating_s);
			sem_post(ph->finish_dining_s);
			return ;
		}
		sem_post(ph->eating_s);
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
			sem_wait(ph[i].must_eat_s);
			sem_post(ph[i].must_eat_s);
			usleep(1000);
		}
	}
	print_ph_state(ph, MUST_EAT_REACHED);
	sem_post(ph->finish_dining_s);
}

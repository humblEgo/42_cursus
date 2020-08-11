/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_ph_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:06:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/11 14:21:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	picking_up_forks(t_ph *ph)
{
	pthread_mutex_lock(&ph->left_fork->fork_m);
	print_ph_state(ph, PICKING_FORK);
	pthread_mutex_lock(&ph->right_fork->fork_m);
	print_ph_state(ph, PICKING_FORK);
}

void	eating(t_ph *ph)
{
	pthread_mutex_lock(&ph->eating_m);
	ph->last_eat_time = get_cur_time();
	print_ph_state(ph, EATING);
	usleep(ph->cond->time_to_eat * 1000);
	ph->num_of_meals++;
	if (ph->num_of_meals == ph->cond->count_must_eat)
		pthread_mutex_unlock(&ph->must_eat_m);
	pthread_mutex_unlock(&ph->left_fork->fork_m);
	pthread_mutex_unlock(&ph->right_fork->fork_m);
	pthread_mutex_unlock(&ph->eating_m);
}

void	sleeping(t_ph *ph)
{
	print_ph_state(ph, SLEEPING);
	usleep(ph->cond->time_to_sleep * 1000);
}

void	thinking(t_ph *ph)
{
	print_ph_state(ph, THINKING);
}

void	*routine_ph(void *ph_void)
{
	t_ph *ph;

	ph = (t_ph *)ph_void;
	while (1)
	{
		unlock_m_if_done(ph, FORK_M_UNLOCKED);
		picking_up_forks(ph);
		unlock_m_if_done(ph, FORK_M_LOCKED);
		eating(ph);
		unlock_m_if_done(ph, FORK_M_UNLOCKED);
		sleeping(ph);
		unlock_m_if_done(ph, FORK_M_UNLOCKED);
		thinking(ph);
	}
	return ((void *)TRUE);
}

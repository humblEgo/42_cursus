/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_ph_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:06:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/06 16:06:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	pick_up_fork(t_ph *ph, t_fork *fork)
{
	pthread_mutex_lock(&fork->fork_m);
	print_ph_state(ph, PICKING_FORK);
}

void	picking_up_forks(t_ph *ph)
{
	if (ph->ph_num % 2 == 0)
	{
		pick_up_fork(ph, ph->right_fork);
		pick_up_fork(ph, ph->left_fork);
	}
	else
	{
		pick_up_fork(ph, ph->left_fork);
		pick_up_fork(ph, ph->right_fork);
	}
}

void	eating(t_ph *ph)
{
	pthread_mutex_lock(&ph->eating_m);
	print_ph_state(ph, EATING);
	usleep(ph->cond->time_to_eat * 1000);
	ph->last_eat_time = get_cur_time();
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

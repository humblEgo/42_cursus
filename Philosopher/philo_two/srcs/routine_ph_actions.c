/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_ph_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:06:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/13 01:37:59 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	picking_up_forks(t_ph *ph)
{
	sem_wait(ph->forks_s);
	print_ph_state(ph, PICKING_FORK);
	sem_wait(ph->forks_s);
	print_ph_state(ph, PICKING_FORK);
}

void	eating(t_ph *ph)
{
	sem_wait(ph->eating_s);
	ph->last_eat_time = get_cur_time();
	print_ph_state(ph, EATING);
	sem_post(ph->eating_s);
	usleep(ph->cond->time_to_eat * 1000);
	ph->num_of_meals++;
	if (ph->num_of_meals == ph->cond->count_must_eat)
		sem_post(ph->must_eat_s);
}

void	put_down_forks(t_ph *ph)
{
	sem_post(ph->forks_s);
	print_ph_state(ph, -1000);
	sem_post(ph->forks_s);
	print_ph_state(ph, -1000);
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

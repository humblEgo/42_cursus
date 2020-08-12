/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_ph_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:06:29 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/12 11:09:40 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	picking_up_forks(t_ph *ph)
{
	sem_wait(ph->forks);
	print_ph_state(ph, PICKING_FORK);
	sem_wait(ph->forks);
	print_ph_state(ph, PICKING_FORK);
}

void	eating(t_ph *ph)
{
	sem_wait(ph->eating_s);
	ph->last_eat_time = get_cur_time();
	print_ph_state(ph, EATING);
	usleep(ph->cond->time_to_eat * 1000);
	ph->num_of_meals++;
	if (ph->num_of_meals == ph->cond->count_must_eat)
		sem_post(ph->must_eat_s);
	sem_post(ph->eating_s);
}

void	put_down_forks(t_ph *ph)
{
	sem_post(ph->forks);
	sem_post(ph->forks);
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

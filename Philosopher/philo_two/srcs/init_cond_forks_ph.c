/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cond_forks_ph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:02:07 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/10 20:05:43 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			init_cond(t_ph_info *ph_info, int argc, char **argv)
{
	if (!(ph_info->cond = (t_cond *)malloc(sizeof(t_cond))))
		return (FALSE);
	ph_info->cond->num_of_ph = ft_atoi(argv[0]);
	ph_info->cond->time_to_die = ft_atoi(argv[1]);
	ph_info->cond->time_to_eat = ft_atoi(argv[2]);
	ph_info->cond->time_to_sleep = ft_atoi(argv[3]);
	ph_info->cond->count_must_eat = -1;
	if (argc == 6)
		ph_info->cond->count_must_eat = ft_atoi(argv[4]);
	return (TRUE);
}

int			init_forks(t_ph_info *ph_info)
{
	ph_info->forks = ft_sem_open(FORK_S, ph_info->cond->num_of_ph);
	return (TRUE);
}

static void	set_fork_on_the_table(t_ph_info *ph_info)
{
	int num_of_ph;
	int i;

	num_of_ph = ph_info->cond->num_of_ph;
	i = -1;
	while (++i < num_of_ph)
		ph_info->ph[i].forks = ph_info->forks;
}

static void	init_and_lock_ph_m(t_ph *ph, int ph_num)
{
	char buf[BUFFER_SIZE];

	if (!(make_sem_name_in_buf(buf, LAST_EAT_TIME_S, ph_num)))
		return ;
	ph->last_eat_time_s = ft_sem_open(buf, 1);
	if (!(make_sem_name_in_buf(buf, EATING_S, ph_num)))
		return ;
	ph->eating_s = ft_sem_open(buf, 1);
	if (!(make_sem_name_in_buf(buf, MUST_EAT_S, ph_num)))
		return ;
	ph->must_eat_s = ft_sem_open(buf, 1);
	sem_wait(ph->must_eat_s);
}

int			init_ph(t_ph_info *ph_info)
{
	int num_of_ph;
	int i;

	num_of_ph = ph_info->cond->num_of_ph;
	if (!(ph_info->ph = (t_ph *)malloc(sizeof(t_ph) * num_of_ph)))
		return (FALSE);
	i = -1;
	while (++i < num_of_ph)
	{
		ph_info->ph[i].ph_num = i + 1;
		ph_info->ph[i].num_of_meals = 0;
		ph_info->ph[i].start_time = &ph_info->start_time;
		ph_info->ph[i].cond = ph_info->cond;
		ph_info->ph[i].msg_s = ph_info->msg_s;
		ph_info->ph[i].finish_dining_s = ph_info->finish_dining_s;
		init_and_lock_ph_m(&ph_info->ph[i], ph_info->ph[i].ph_num);
	}
	set_fork_on_the_table(ph_info);
	return (TRUE);
}
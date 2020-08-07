/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:02:07 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/07 15:31:08 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	init_cond(t_ph_info *ph_info, int argc, char **argv)
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

static int	init_forks(t_ph_info *ph_info)
{
	int num_of_ph;
	int i;

	num_of_ph = ph_info->cond->num_of_ph;
	if (!(ph_info->forks = (t_fork *)malloc(sizeof(t_fork) * num_of_ph)))
		return (FALSE);
	i = -1;
	while (++i < num_of_ph)
		pthread_mutex_init(&(ph_info->forks[i].fork_m), NULL);
	return (TRUE);
}

static void	set_fork_between_ph(t_ph_info *ph_info)
{
	int num_of_ph;
	int i;

	num_of_ph = ph_info->cond->num_of_ph;
	i = -1;
	while (++i < num_of_ph)
	{
		if (i == 0)
			ph_info->ph[i].right_fork = &ph_info->forks[num_of_ph - 1];
		else
			ph_info->ph[i].right_fork = &ph_info->forks[i - 1];
		ph_info->ph[i].left_fork = &ph_info->forks[i];
	}
}

static int	init_ph(t_ph_info *ph_info)
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

		ph_info->ph[i].is_all_unlocked = &ph_info->is_all_unlocked;
		ph_info->ph[i].ensure_unlock_m = &ph_info->ensure_unlock_m;
		pthread_mutex_init(&ph_info->ph[i].ensure_ph_unlock_m, NULL);
		pthread_mutex_init(&ph_info->ph[i].ensure_monitor_unlock_m, NULL);
		pthread_mutex_lock(&ph_info->ph[i].ensure_ph_unlock_m);
		pthread_mutex_lock(&ph_info->ph[i].ensure_monitor_unlock_m);

		pthread_mutex_init(&ph_info->ph[i].last_eat_time_m, NULL);
		pthread_mutex_init(&ph_info->ph[i].eating_m, NULL);
		ph_info->ph[i].msg_m = &ph_info->msg_m;
		pthread_mutex_init(&ph_info->ph[i].must_eat_m, NULL);
		pthread_mutex_lock(&ph_info->ph[i].must_eat_m);
		ph_info->ph[i].finish_dining_m = &ph_info->finish_dining_m;
	}
	set_fork_between_ph(ph_info);
	return (TRUE);
}

int			init_ph_info(t_ph_info *ph_info, int argc, char **argv)
{
	ph_info->cond = NULL;
	ph_info->ph = NULL;
	ph_info->forks = NULL;

	ph_info->is_all_unlocked = FALSE;
	pthread_mutex_init(&ph_info->ensure_unlock_m, NULL);

	pthread_mutex_init(&ph_info->msg_m, NULL);
	pthread_mutex_init(&ph_info->finish_dining_m, NULL);
	pthread_mutex_lock(&ph_info->finish_dining_m);
	if ((ph_info->start_time = get_cur_time()) < -1)
		return (FALSE);
	if (!init_cond(ph_info, argc, argv))
		return (FALSE);
	if (!init_forks(ph_info))
		return (FALSE);
	if (!init_ph(ph_info))
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:58:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/09 14:40:18 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}

void	destroy_m_forks(t_fork *forks, int n_of_ph)
{
	int i;

	i = -1;
	while (++i < n_of_ph)
		pthread_mutex_destroy(&forks[i].fork_m);
}

void	destroy_m_ph_info(t_ph_info *ph_info)
{
	pthread_mutex_destroy(&ph_info->msg_m);
	pthread_mutex_destroy(&ph_info->finish_dining_m);
	pthread_mutex_destroy(&ph_info->ensure_unlock_m);
}

void	destroy_m_ph(t_ph *ph, int n_of_ph)
{
	int i;

	i = -1;
	while (++i < n_of_ph)
	{
		pthread_mutex_destroy(&ph[i].last_eat_time_m);
		pthread_mutex_destroy(&ph[i].eating_m);
		pthread_mutex_destroy(&ph[i].must_eat_m);
		pthread_mutex_destroy(&ph[i].ensure_ph_unlock_m);
	}
}

void	destroy_m_monitor(t_ph *ph, int n_of_monitor)
{
	int i;

	i = -1;
	while (++i < n_of_monitor)
	{
		pthread_mutex_destroy(&ph[i].ensure_monitor_unlock_m);
	}
}

void	destroy_m_all(t_ph_info *ph_info, int n_of_ph, int n_of_monitor)
{
	if (ph_info->ph)
	{
		destroy_m_ph(ph_info->ph, n_of_ph);
		destroy_m_monitor(ph_info->ph, n_of_monitor);
	}
	if (ph_info->forks)
		destroy_m_forks(ph_info->forks, n_of_ph);
	destroy_m_ph_info(ph_info);
}

void	get_num_of_threads(int err_n, int *n_of_ph, int *n_of_monitor, 
															t_ph_info *ph_info)
{
	int i;

	if (err_n == NO_ERROR)
	{
		*n_of_ph = ph_info->cond->num_of_ph;
		*n_of_monitor = *n_of_ph;
	}
	else if (err_n == INIT_ERRNO || err_n == CREATE_MONITOR_EC_ERRNO)
	{
		*n_of_ph = 0;
		*n_of_monitor = 0;
	}
	else if (err_n >= CREATE_MONITOR_PH_ERRNO)
	{
		i = err_n - CREATE_MONITOR_PH_ERRNO;
		*n_of_ph = (i - 1 == 0) ? 0 : (i - 1);
		*n_of_monitor = *n_of_ph;
	}
	else if (err_n >= CREATE_ROUTINE_PH_ERRNO)
	{
		i = err_n - CREATE_ROUTINE_PH_ERRNO;
		*n_of_ph = (i - 1 == 0) ? 0 : (i - 1);
		*n_of_monitor = *n_of_ph + 1;
	}
}

int		clean_all(t_ph_info *ph_info, int err_n)
{
	int n_of_ph;
	int n_of_monitor;

	n_of_ph = 0;
	n_of_monitor = 0;
	if (err_n != NO_ERROR)
		pthread_mutex_unlock(&ph_info->finish_dining_m);
	get_num_of_threads(err_n, &n_of_ph, &n_of_monitor, ph_info);
	wait_all_m_unlocked(ph_info, n_of_ph, n_of_monitor);
	destroy_m_all(ph_info, n_of_ph, n_of_monitor);
	ft_free(ph_info->cond);
	ft_free(ph_info->ph);
	ft_free(ph_info->forks);
	ph_info->cond = NULL;
	ph_info->ph = NULL;
	ph_info->forks = NULL;
	ph_info = NULL;
	return (0);
}

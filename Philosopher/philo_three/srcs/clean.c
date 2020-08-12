/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:58:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/12 23:31:17 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}

void	get_num_of_threads(int err_n, int *n_of_ph, int *n_of_monitor, \
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
		sem_post(ph_info->finish_dining_s);
	get_num_of_threads(err_n, &n_of_ph, &n_of_monitor, ph_info);
	unlink_s_all(ph_info, n_of_ph);
	ft_free(ph_info->cond);
	ft_free(ph_info->ph);
	ph_info->cond = NULL;
	ph_info->ph = NULL;
	ph_info = NULL;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ph_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:14:58 by humblego          #+#    #+#             */
/*   Updated: 2020/08/09 17:14:59 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			init_ph_info(t_ph_info *ph_info, int argc, char **argv)
{
	ph_info->cond = NULL;
	ph_info->ph = NULL;
	ph_info->forks = NULL;
	ph_info->let_all_m_unlock = FALSE;
	pthread_mutex_init(&ph_info->ensure_unlock_m, NULL);
	pthread_mutex_init(&ph_info->msg_m, NULL);
	pthread_mutex_init(&ph_info->finish_dining_m, NULL);
	pthread_mutex_lock(&ph_info->finish_dining_m);
	if ((ph_info->start_time = get_cur_time()) < -1)
		return (error(GET_TIME) + INIT_ERRNO);
	if (!init_cond(ph_info, argc, argv))
		return (INIT_ERRNO);
	if (!init_forks(ph_info))
		return (INIT_ERRNO);
	if (!init_ph(ph_info))
		return (INIT_ERRNO);
	return (TRUE);
}

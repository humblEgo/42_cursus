/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ph_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:14:58 by humblego          #+#    #+#             */
/*   Updated: 2020/08/12 11:24:52 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			init_ph_info(t_ph_info *ph_info, int argc, char **argv)
{
	ph_info->cond = NULL;
	ph_info->ph = NULL;
	ph_info->forks = NULL;
	ph_info->msg_s = ft_sem_open(MSG_S, 1);
	ph_info->finish_dining_s = ft_sem_open(FINISH_DINING_S, 1);
	sem_wait(ph_info->finish_dining_s);
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

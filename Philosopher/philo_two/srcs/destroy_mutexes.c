/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:23:21 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/10 18:04:00 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	unlink_s_ph_info(t_ph_info *ph_info)
{
	//TODO: delete void
	(void)ph_info;
	sem_unlink(FORK_S);
	sem_unlink(MSG_S);
	sem_unlink(FINISH_DINING_S);
}

static void	unlink_s_ph(t_ph *ph, int n_of_ph)
{
	int 	i;
	char	buf[BUFFER_SIZE];

	//TODO delete void
	(void)ph;
	i = -1;
	while (++i < n_of_ph)
	{
		if (!make_sem_name_in_buf(buf, LAST_EAT_TIME_S, i))
			return ;
		sem_unlink(buf);
		if (!make_sem_name_in_buf(buf, EATING_S, i))
			return ;
		sem_unlink(buf);
		if (!make_sem_name_in_buf(buf, MUST_EAT_S, i))
			return ;
		sem_unlink(buf);
	}
}

void		unlink_s_all(t_ph_info *ph_info, int n_of_ph, int n_of_monitor)
{
	//TODO: check it
	(void)n_of_monitor;
	if (ph_info->ph)
		unlink_s_ph(ph_info->ph, n_of_ph);
	unlink_s_ph_info(ph_info);
}

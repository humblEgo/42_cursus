/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_semaphores.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:23:21 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/12 23:47:10 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	unlink_s_ph_info(t_ph_info *ph_info)
{
	sem_close(ph_info->forks_s);
	sem_unlink(FORK_S);
	sem_close(ph_info->msg_s);
	sem_unlink(MSG_S);
	sem_close(ph_info->finish_dining_s);
	sem_unlink(FINISH_DINING_S);
}

static void	unlink_s_ph(t_ph_info *ph_info, int n_of_ph)
{
	int		i;
	char	buf[BUFFER_SIZE];

	i = -1;
	while (++i < n_of_ph)
	{
		if (!make_sem_name_in_buf(buf, EATING_S, i))
			return ;
		sem_close(ph_info->ph[i].eating_s);
		sem_unlink(buf);
		if (!make_sem_name_in_buf(buf, MUST_EAT_S, i))
			return ;
		sem_close(ph_info->ph[i].must_eat_s);
		sem_unlink(buf);
	}
}

void		unlink_s_all(t_ph_info *ph_info, int n_of_ph)
{
	if (ph_info->ph)
		unlink_s_ph(ph_info, n_of_ph);
	unlink_s_ph_info(ph_info);
}

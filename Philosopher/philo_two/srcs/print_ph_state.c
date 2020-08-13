/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ph_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:05:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/13 01:35:06 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	print_state(int state_type)
{
	if (state_type == PICKING_FORK)
		ft_putstr_fd(" has taken a fork\n", 1);
	else if (state_type == EATING)
		ft_putstr_fd(" is eating\n", 1);
	else if (state_type == SLEEPING)
		ft_putstr_fd(" is sleeping\n", 1);
	else if (state_type == THINKING)
		ft_putstr_fd(" is thinking\n", 1);
	else if (state_type == DIED)
		ft_putstr_fd(" died\n", 1);
	else if (state_type == MUST_EAT_REACHED)
		ft_putstr_fd("All philosophers ate enough :)\n", 1);
	else if (state_type == -1000)
		ft_putstr_fd("put down forks\n", 1);
}

void	print_ph_state(t_ph *ph, int state_type)
{
	static int is_print_end;

	sem_wait(ph->msg_s);
	if (is_print_end)
	{
		sem_post(ph->msg_s);
		return ;
	}
	if (state_type == DIED || state_type == MUST_EAT_REACHED)
	{
		is_print_end = TRUE;
		if (state_type == MUST_EAT_REACHED)
		{
			print_state(MUST_EAT_REACHED);
			sem_post(ph->msg_s);
			return ;
		}
	}
	ft_putnbr_fd((int)(get_cur_time() - *ph->start_time), 1);
	write(1, " ", 1);
	ft_putnbr_fd(ph->ph_num, 1);
	print_state(state_type);
	sem_post(ph->msg_s);
}

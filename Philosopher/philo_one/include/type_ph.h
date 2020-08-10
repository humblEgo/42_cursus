/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ph.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/10 21:36:09 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_PH_H
# define TYPE_PH_H

typedef struct	s_cond
{
	int				num_of_ph;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_must_eat;
}				t_cond;

typedef struct	s_fork
{
	pthread_mutex_t fork_m;
}				t_fork;

typedef struct	s_ph
{
	int				ph_num;
	int				num_of_meals;
	int				*let_all_m_unlock;
	int				is_eating_now;
	long long		*start_time;
	long long		last_eat_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_cond			*cond;
	pthread_mutex_t	last_eat_time_m;
	pthread_mutex_t	eating_m;
	pthread_mutex_t	must_eat_m;
	pthread_mutex_t	*msg_m;
	pthread_mutex_t	*finish_dining_m;
	pthread_mutex_t *ensure_unlock_m;
	pthread_mutex_t ensure_ph_unlock_m;
	pthread_mutex_t ensure_monitor_unlock_m;
}				t_ph;

typedef struct	s_ph_info
{
	t_cond			*cond;
	t_ph			*ph;
	t_fork			*forks;
	long long		start_time;
	int				let_all_m_unlock;
	pthread_mutex_t	msg_m;
	pthread_mutex_t	finish_dining_m;
	pthread_mutex_t ensure_unlock_m;
}				t_ph_info;

#endif

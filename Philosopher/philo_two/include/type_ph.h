/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ph.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:25 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/11 22:52:36 by iwoo             ###   ########.fr       */
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

typedef struct	s_ph
{
	int				ph_num;
	int				num_of_meals;
	long long		*start_time;
	long long		last_eat_time;
	t_cond			*cond;
	sem_t			*forks;
	sem_t			*eating_s;
	sem_t			*must_eat_s;
	sem_t			*msg_s;
	sem_t			*finish_dining_s;
}				t_ph;

typedef struct	s_ph_info
{
	t_cond			*cond;
	t_ph			*ph;
	sem_t			*forks;
	long long		start_time;
	sem_t			*msg_s;
	sem_t			*finish_dining_s;
}				t_ph_info;

#endif

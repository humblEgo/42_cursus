/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humblego <humblego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:26 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/09 00:53:46 by humblego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include "macro_ph.h"
# include "type_ph.h"

void		ensure_unlock(t_ph *ph);
void		ensure_unlock_before_eating(t_ph *ph);
void		ensure_monitor_unlock(t_ph *ph);
void		wait_all_m_unlocked(t_ph_info *ph_info, int n_of_ph, int n_of_monitor);

/*
** 	init.c
*/

int			init_ph_info(t_ph_info *ph_info, int argc, char **argv);

/*
**	error.c
*/

int			error(char *msg);

/*
** 	clean.c
*/

int			clean_all(t_ph_info *ph_info, int error_no);

/*
** 	monitor.c
*/

void		monitor_ph(t_ph *ph);
void		monitor_eat_count(t_ph_info *ph_info);

/*
** 	routine_ph_actions.c
*/

void		picking_up_forks(t_ph *ph);
void		eating(t_ph *ph);
void		sleeping(t_ph *ph);
void		thinking(t_ph *ph);

/*
** 	print_ph_state.c
*/

void		print_ph_state(t_ph *ph, int state_type);

/*
** 	create_detached_thread.c
*/

int			create_detached_thread(pthread_t *tid, void *funcion,
										void *arg, int arg_type);

/*
** 	ft_atoi.c
*/

int			ft_atoi(const char *nptr);

/*
** 	utils.c
*/

void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
long long	get_cur_time(void);
int			is_num_str(char *str);

#endif

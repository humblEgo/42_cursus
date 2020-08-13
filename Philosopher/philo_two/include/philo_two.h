/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:18:26 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/13 00:48:25 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>
# include "macro_ph.h"
# include "type_ph.h"

/*
** 	semaphore.c
*/

sem_t		*ft_sem_open(char *name, int value);
int			make_sem_name_in_buf(char *buf, char *src, int ph_num);

/*
** 	init_ph_info.c
*/

int			init_ph_info(t_ph_info *ph_info, int argc, char **argv);

/*
** 	init_cond_forks_ph.c
*/

int			init_cond(t_ph_info *ph_info, int argc, char **argv);
int			init_forks(t_ph_info *ph_info);
int			init_ph(t_ph_info *ph_info);

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
void		put_down_forks(t_ph *ph);
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
** 	unlink_semaphores.c
*/

void		unlink_s_all(t_ph_info *ph_info, int n_of_ph);

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
int			ft_strlen(char *str);

#endif

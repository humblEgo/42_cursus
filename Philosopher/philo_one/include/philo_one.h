#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include "macro_ph.h"

typedef struct  s_cond
{
	int             num_of_ph;
	int             time_to_die;
	int             time_to_eat;
	int             time_to_sleep;
	int             count_must_eat;
}               t_cond;

typedef struct  s_fork
{
	pthread_mutex_t fork_m;
}               t_fork;

typedef struct  s_ph
{
	int         ph_num;
	int         num_of_meals;
	long long	*start_time;
	long long   last_eat_time;
	t_fork      *left_fork;
	t_fork      *right_fork;
	t_cond      *cond;
	pthread_mutex_t last_eat_time_m;
	pthread_mutex_t eating_m;
	pthread_mutex_t	must_eat_m;
	pthread_mutex_t *msg_m;
	pthread_mutex_t *finish_dining_m;
}               t_ph;

typedef struct  s_ph_info
{
	t_cond      	*cond;
	t_ph        	*ph;
	t_fork      	*forks;
	long long		start_time;
	pthread_mutex_t	msg_m;
	pthread_mutex_t	finish_dining_m;
}               t_ph_info;

int			ft_atoi(const char *nptr);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
long long	get_cur_time(void);
int			is_num_str(char *str);

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

int			clean_ph_info(t_ph_info	*ph_info);

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

int			create_detached_thread(pthread_t *tid, void *funcion, \
										void *arg, int arg_type);

#endif
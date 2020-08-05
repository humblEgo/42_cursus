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
	int             picked;
	int             fork_num;
	pthread_mutex_t fork_m;
}               t_fork;

typedef struct  s_ph
{
	int         ph_num;
	int         num_of_meals;
	int			is_eating_now;
	long long	*start_time;
	long long   last_eat_time;
	t_fork      *left_fork;
	t_fork      *right_fork;
	t_cond      *cond;
	pthread_mutex_t *finish_dining_m;
	pthread_mutex_t eating_m;
	pthread_mutex_t	must_eat;
	pthread_mutex_t *msg_m;
}               t_ph;

typedef struct  s_ph_info
{
	t_cond      *cond;
	t_ph        *ph;
	t_fork      *forks;
	long long	start_time;
	pthread_mutex_t msg_m;
	pthread_mutex_t finish_dining_m;
}               t_ph_info;

int			ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr_fd(char *s, int fd);
long long	get_cur_time(void);
int			is_num_str(char *str);
void		ft_putnbr_fd(int i, int fd);

int			init_ph_info(t_ph_info *ph_info, int argc, char **argv);

void		monitor_ph(t_ph *ph);
void		monitor_eat_count(t_ph_info *ph_info);

void		ph_routine(void *ph_void);

void		print_state(t_ph *ph, char *state);
void		print_ate_enough(t_ph_info *ph);

#endif
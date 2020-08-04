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
	int             time_ph_must_eat;
}               t_cond;

typedef struct  s_fork
{
	int             picked;
	int             fork_num;
	pthread_mutex_t fork_m;
}               t_fork;

typedef struct  s_ph
{
	pthread_t   thread;
	int         ph_num;
	int         num_of_meals;
	int         last_eat_time;
	int         is_eating_now;
	t_fork      *left_fork;
	t_fork      *right_fork;
	t_cond      *cond;
	pthread_mutex_t mutex;
	pthread_mutex_t *msg_m;
	pthread_mutex_t *someone_died_m;
}               t_ph;

typedef struct  s_ph_info
{
	t_cond      *cond;
	t_ph        *ph;
	t_fork      *forks;
	pthread_mutex_t msg_m;
	pthread_mutex_t someone_died_m;
}               t_ph_info;

int			ft_atoi(const char *nptr);
void		ft_putstr_fd(char *s, int fd);
long long	get_cur_time(void);
int			is_num_str(char *str);

int			init_ph_info(t_ph_info *ph_info, int argc, char **argv);

void		print_status(t_ph *ph, char *state);

#endif
#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

typedef struct  s_fork
{
    int             picked;
    pthread_mutex_t fork_m;
}               t_fork;

typedef struct  s_ph
{
    pthread_t   tid;
    int         ph_num;
    int         num_of_meals;
    int         last_eat_time;
    t_fork      *left_fork;
    t_fork      *right_fork;
}               t_ph;

typedef struct  s_cond
{
    int             num_of_ph;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_ph_must_eat;
    int             time_start;
}               t_cond;

typedef struct  s_ph_info
{
    t_cond      *cond;
    t_ph        *ph;
    t_fork      *forks;
    pthread_mutex_t     *eats_m;
    pthread_mutex_t     *alive_m;
    pthread_mutex_t     *someone_died_m;
}               t_ph_info;

int			ft_atoi(const char *nptr);
void        ft_putstr_fd(char *s, int fd);

void        print_status_taken_fork(int ph_num);
void        print_status_eating(int ph_num);
void        print_status_sleeping(int ph_num);
void        print_status_thinking(int ph_num);
void        print_status_died(int ph_num);
#endif
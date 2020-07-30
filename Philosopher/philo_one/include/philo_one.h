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

typedef struct  s_ph_state
{
    pthread_mutex_t *mutex;
    pthread_cond_t  *cond;
    int             *fork;
}               t_ph_state;

typedef struct  s_ph_info
{
    int num_of_ph;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_ph_must_eat;
}               t_ph_info;

t_ph_state  g_ph_state;

int			ft_atoi(const char *nptr);
void        ft_putstr_fd(char *s, int fd);

void        print_status_taken_fork(int ph_num);
void        print_status_eating(int ph_num);
void        print_status_sleeping(int ph_num);
void        print_status_thinking(int ph_num);
void        print_status_died(int ph_num);
#endif
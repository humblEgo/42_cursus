#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

pthread_mutex_t *g_mutex;
pthread_cond_t  *g_cond;

typedef struct  s_ph_info
{
    int num_of_ph;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_ph_must_eat;
}               t_ph_info;

int			ft_atoi(const char *nptr);
void        ft_putstr_fd(char *s, int fd);

void        print_status_taken_fork(int ph_num);
#endif
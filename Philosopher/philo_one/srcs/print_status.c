#include "philo_one.h"

void    print_status(t_ph *ph, char *state)
{
    struct timeval tv;

    //TODO: printf는 허용이 안된데이~
    pthread_mutex_lock(ph->msg_m);
    if (gettimeofday(&tv, NULL))
    {
        ft_putstr_fd("gettimeofday error\n", 2);
        return ;
    }
    printf("%ld ", tv.tv_usec);
    printf("%d ", ph->ph_num);
    printf("%s\n", state);
    pthread_mutex_unlock(ph->msg_m);
}
#include "philo_one.h"

void    print_status(t_ph *ph, char *state)
{

    //TODO: printf는 허용이 안된데이~
    pthread_mutex_lock(ph->msg_m);
    printf("%lld ", get_cur_time());
    printf("%d ", ph->ph_num);
    printf("%s\n", state);
    pthread_mutex_unlock(ph->msg_m);
}
#include "philo_one.h"

int create_detached_thread(pthread_t *tid, void *function, void *arg, int arg_type)
{
    if (arg_type == PH)
    {
        if (pthread_create(tid, NULL, function, (t_ph *)arg))
            return (FALSE);
    }
    else if (arg_type == PH_INFO)
    {
        if (pthread_create(tid, NULL, function, (t_ph_info *)arg))
            return (FALSE);
    }
    else
        return (error("Invalid arg_type\n"));
    pthread_detach(*tid);
    return (TRUE);
}
#include "philo_one.h"

void    print_status_taken_fork(int ph_num)
{
    struct timeval tv;

    //TODO: change printf to allowed function
    if (gettimeofday(&tv, NULL))
    {
        ft_putstr_fd("gettimeofday error\n", 2);
        return ;
    }
    printf("%d %d has taken a fork\n", tv.tv_usec, ph_num);
}

void    print_status_eating(int ph_num)
{
    (void)ph_num;
}

void    print_status_sleeping(int ph_num)
{
    (void)ph_num;
}

void    pirnt_status_thinking(int ph_num)
{
    (void)ph_num;
}

void    print_status_died(int ph_num)
{
    (void)ph_num;
}
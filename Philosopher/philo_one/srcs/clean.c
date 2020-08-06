#include "philo_one.h"

void    ft_free(void *ptr)
{
    if (!ptr)
        return ;
    free(ptr);
}


int clean_ph_info(t_ph_info *ph_info)
{
    ft_free(ph_info->cond);
    ft_free(ph_info->ph);
    ft_free(ph_info->forks);
    ph_info->cond = NULL;
    ph_info->ph = NULL;
    ph_info->forks = NULL;
    ph_info = NULL;
    return (0);
}
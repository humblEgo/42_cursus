#include "philo_one.h"

void    set_cond(t_cond *cond, int argc, char **argv)
{
    cond->num_of_ph = ft_atoi(argv[0]);
    cond->time_to_die = ft_atoi(argv[1]);
    cond->time_to_eat = ft_atoi(argv[2]);
    cond->time_to_sleep = ft_atoi(argv[3]);
    cond->count_must_eat = -1;
    if (argc == 6)
        cond->count_must_eat = ft_atoi(argv[4]);
}

int init_ph_info(t_ph_info *ph_info, int argc, char **argv)
{
    t_cond  *cond;
    t_fork  *forks;
    t_ph    *ph;
    int     i;

    //TODO: malloc guard
    ph_info->start_time = get_cur_time();
    if (!(ph_info->cond = (t_cond *)malloc(sizeof(t_cond))))
        return (FALSE);
    cond = ph_info->cond;
    set_cond(cond, argc, argv);
    ph_info->forks = (t_fork *)malloc(sizeof(t_fork) * cond->num_of_ph);
    forks = ph_info->forks;
    ph_info->ph = (t_ph *)malloc(sizeof(t_ph) * cond->num_of_ph);
    ph = ph_info->ph;
    pthread_mutex_init(&ph_info->msg_m, NULL);
    pthread_mutex_init(&ph_info->finish_dining_m, NULL);
    pthread_mutex_lock(&ph_info->finish_dining_m);

    i = -1;
    while (++i < cond->num_of_ph)
    {
        pthread_mutex_init(&(forks[i].fork_m), NULL);
        forks[i].fork_num = i + 1; // 시험용
    } 
    
    //Set ph
    i = -1;
    while (++i < cond->num_of_ph)
    {
        ph[i].ph_num = i + 1;
        ph[i].start_time = &ph_info->start_time;
        ph[i].cond = cond;
        pthread_mutex_init(&ph[i].last_eat_time_m, NULL);
        pthread_mutex_init(&ph[i].must_eat, NULL);
        pthread_mutex_lock(&ph[i].must_eat);
        ph[i].msg_m = &ph_info->msg_m;
        ph[i].finish_dining_m = &ph_info->finish_dining_m;
        ph[i].num_of_meals = 0;
        ph[i].is_eating_now = FALSE;
    }

    //Set fork on table
    i = -1;
    while (++i < cond->num_of_ph)
    {
        if (i == 0)
            ph[i].right_fork = &forks[cond->num_of_ph - 1];
        else
            ph[i].right_fork = &forks[i - 1];
        ph[i].left_fork = &forks[i];
    }
    return (TRUE);
}

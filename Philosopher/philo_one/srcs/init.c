#include "philo_one.h"

static int  init_ph_info(t_ph_info *ph_info)
{
    ph_info->cond = NULL;
    ph_info->ph = NULL;
    ph_info->forks = NULL;
    if ((ph_info->start_time = get_cur_time()) < -1)
        return (FALSE);
    return (TRUE);
}

void    parse_argv(t_cond *cond, int argc, char **argv)
{
    cond->num_of_ph = ft_atoi(argv[0]);
    cond->time_to_die = ft_atoi(argv[1]);
    cond->time_to_eat = ft_atoi(argv[2]);
    cond->time_to_sleep = ft_atoi(argv[3]);
    cond->count_must_eat = -1;
    if (argc == 6)
        cond->count_must_eat = ft_atoi(argv[4]);
}

int     init_cond(t_ph_info *ph_info, int argc, char **argv)
{
    if (!(ph_info->cond = (t_cond *)malloc(sizeof(t_cond))))
        return (FALSE);
    parse_argv(ph_info->cond, argc, argv);
    return (TRUE);
}

int     init_forks(t_ph_info *ph_info)
{
    int num_of_ph;
    int i;

    num_of_ph = ph_info->cond->num_of_ph;
    if (!(ph_info->forks = (t_fork *)malloc(sizeof(t_fork) * num_of_ph)))
        return (FALSE);
    i = -1;
    while (++i < num_of_ph)
        pthread_mutex_init(&(ph_info->forks[i].fork_m), NULL);
    return (TRUE);
}

void    set_fork_between_ph(t_ph *ph, t_fork *forks)
{
    int num_of_ph;
    int i;

    num_of_ph = ph->cond->num_of_ph;
    i = -1;
    while (++i < num_of_ph)
    {
        if (i == 0)
            ph[i].right_fork = &forks[num_of_ph - 1];
        else
            ph[i].right_fork = &forks[i - 1];
        ph[i].left_fork = &forks[i];
    }
}

int     init_ph(t_ph_info *ph_info)
{
    int     num_of_ph;
    int     i;
    t_ph    *ph;

    ph = ph_info->ph;
    num_of_ph = ph_info->cond->num_of_ph;
    if (!(ph_info->ph = (t_ph *)malloc(sizeof(t_ph) * num_of_ph)))
        return (FALSE);
    i = -1;
    while (++i < num_of_ph)
    {
        ph[i].ph_num = i + 1;
        ph[i].start_time = &ph_info->start_time;
        ph[i].cond = ph_info->cond;
        pthread_mutex_init(&ph[i].last_eat_time_m, NULL);
        pthread_mutex_init(&ph[i].must_eat, NULL);
        pthread_mutex_lock(&ph[i].must_eat);
        ph[i].msg_m = &ph_info->msg_m;
        ph[i].finish_dining_m = &ph_info->finish_dining_m;
        ph[i].num_of_meals = 0;
        ph[i].is_eating_now = FALSE;
        set_fork_between_ph(&ph[i], ph_info->forks);
    }
    return (TRUE);
}

int     init_ph_and_dining(t_ph_info *ph_info, int argc, char **argv)
{
    if (!init_ph_info(ph_info))
        return (FALSE);
    if (!init_cond(ph_info, argc, argv))
        return (FALSE);
    if (!init_forks(ph_info))
        return (FALSE);
    if (!init_ph(ph_info))
        return (FALSE);
    pthread_mutex_init(&ph_info->msg_m, NULL);
    pthread_mutex_init(&ph_info->finish_dining_m, NULL);
    pthread_mutex_lock(&ph_info->finish_dining_m);
    return (TRUE);
}

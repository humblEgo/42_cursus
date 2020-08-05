#include "philo_one.h"

int is_num_str(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (FALSE);
    }
    return (TRUE);
}

int is_valid_arg(char **argv)
{
    int i;

    i = -1;
    while (argv[++i])
    {
        if (!(is_num_str(argv[i])))
            return (FALSE);
    }
    return (TRUE);
}

void    set_cond(t_cond *cond, int argc, char **argv)
{
    cond->num_of_ph = ft_atoi(argv[0]);
    cond->time_to_die = ft_atoi(argv[1]);
    cond->time_to_eat = ft_atoi(argv[2]);
    cond->time_to_sleep = ft_atoi(argv[3]);
    cond->time_ph_must_eat = -1;
    if (argc == 6)
        cond->time_ph_must_eat = ft_atoi(argv[4]);
}

int get_cur_time(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_usec);
}

int init_ph_info(t_ph_info *ph_info, int argc, char **argv)
{
    t_cond  *cond;
    t_fork  *forks;
    t_ph    *ph;
    int     i;

    //TODO: malloc guard
    if (!(ph_info->cond = (t_cond *)malloc(sizeof(t_cond))))
        return (FALSE);
    cond = ph_info->cond;
    set_cond(cond, argc, argv);
    ph_info->forks = (t_fork *)malloc(sizeof(t_fork) * cond->num_of_ph);
    forks = ph_info->forks;
    ph_info->ph = (t_ph *)malloc(sizeof(t_ph) * cond->num_of_ph);
    ph = ph_info->ph;

    //Set ph
    i = -1;
    while (++i < cond->num_of_ph)
        ph[i].ph_num = i + 1;

    //Set fork on table
    i = -1;
    while (++i < cond->num_of_ph)
    {
        if (i == 0)
            ph[i].left_fork = &forks[cond->num_of_ph - 1];
        else
            ph[i].left_fork = &forks[i - 1];
        if (i == cond->num_of_ph - 1)
            ph[i].right_fork = &forks[0];
        else
            ph[i].right_fork = &forks[i];
    }

    cond->time_start = get_cur_time();
    return (TRUE);
}

void    ph_routine(void *ph_void)
{
    t_ph    *ph;

    ph = (t_ph *)ph_void;
    printf("I'm %d philosopher!\n", ph->ph_num);
    sleep(1);
}

int     dining_start(t_ph_info *ph_info)
{
    t_ph        *ph;
    t_cond      *cond;
    int         i;

    ph = ph_info->ph;
    cond = ph_info->cond;
    i = -1;
    while (++i < cond->num_of_ph)
    {
        if(pthread_create(&(ph[i].tid), NULL, (void *)ph_routine, &ph[i]) != 0)
        {
            ft_putstr_fd("Error: failed to create thread\n", 2);
            return (FALSE);
        }
        pthread_detach(ph[i].tid);
    }
    return (TRUE);
}

int main(int argc, char *argv[])
{
    t_ph_info ph_info;

    if (argc < 5 || argc > 6)
        return (0);
    if (is_valid_arg(&argv[1]))
    {
        init_ph_info(&ph_info, argc, &argv[1]);
        dining_start(&ph_info);
    }
    return (0);
}
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

int is_valid(char **argv)
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

void    set_ph_info(t_ph_info *ph_info, int argc, char **argv)
{
    ph_info->num_of_ph = ft_atoi(argv[0]);
    ph_info->time_to_die = ft_atoi(argv[1]);
    ph_info->time_to_eat = ft_atoi(argv[2]);
    ph_info->time_to_sleep = ft_atoi(argv[3]);
    ph_info->time_ph_must_eat = -1;
    if (argc == 6)
        ph_info->time_ph_must_eat = ft_atoi(argv[4]);
}

int     init_mutex(t_ph_info *ph_info)
{
    int i;

    if (!(g_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1)))
        return (FALSE);
    i = -1;
    while (++i < ph_info->num_of_ph)
        pthread_mutex_init(&g_mutex[i], NULL);
    return (0);
}

void    philosopher_one(t_ph_info *ph_info)
{
    print_status_taken_fork(1);
    if (!(init_mutex(ph_info)))
        return ;
}

int main(int argc, char *argv[])
{
    t_ph_info   ph_info;
//    int         i;

    // TODO: number_of_times_each_philosopher_must_eat
    if ((argc == 5 || argc == 6) && is_valid(&argv[1]))
    {
        set_ph_info(&ph_info, argc, &argv[1]);
        philosopher_one(&ph_info);
        free(g_mutex);
    }
    return (0);
}
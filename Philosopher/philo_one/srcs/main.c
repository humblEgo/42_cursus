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
    pthread_mutex_init(&ph_info->msg_m, NULL);
    pthread_mutex_init(&ph_info->someone_died_m, NULL);
    pthread_mutex_lock(&ph_info->someone_died_m);

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
        ph[i].cond = cond;
        ph[i].msg_m = &ph_info->msg_m;
        ph[i].someone_died_m = &ph_info->someone_died_m;
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

    // i = -1;
    // while (++i < cond->num_of_ph)
    // {
    //     printf("ph %d left fork: %d\n", i, ph[i].left_fork->fork_num);
    //     printf("ph %d right fork: %d\n", i, ph[i].right_fork->fork_num);
    // }
    // cond->time_start = get_cur_time();
    // sleep(5);
    return (TRUE);
}

void    pick_up_fork(t_ph *ph, t_fork *fork)
{
    pthread_mutex_lock(&fork->fork_m);
    print_status(ph, PICKING_FORK);
}

int     eating(t_ph *ph)
{
    print_status(ph, EATING);
    usleep(ph->cond->time_to_eat * 1000);
    return (TRUE);
}

int     putting_down_forks(t_ph *ph)
{
    if (ph->ph_num % 2 == 0)
    {
        pthread_mutex_unlock(&ph->left_fork->fork_m);
        pthread_mutex_unlock(&ph->right_fork->fork_m);
    }
    else
    {
        pthread_mutex_unlock(&ph->right_fork->fork_m);
        pthread_mutex_unlock(&ph->left_fork->fork_m);
    }
    return (TRUE);
}


int     picking_up_forks(t_ph *ph)
{
    if (ph->ph_num % 2 == 0)
    {
        pick_up_fork(ph, ph->left_fork);
        pick_up_fork(ph, ph->right_fork);
    }
    else
    {
        pick_up_fork(ph, ph->right_fork);
        pick_up_fork(ph, ph->left_fork);
    }
    return (TRUE);
}

int     sleeping(t_ph *ph)
{
    print_status(ph, SLEEPING);
    usleep(ph->cond->time_to_sleep * 1000);
    return (TRUE);
}

int     thinking(t_ph *ph)
{
    print_status(ph, THINKING);
    return (TRUE);
}

void    ph_routine(void *ph_void)
{
    t_ph    *ph;

    ph = (t_ph *)ph_void;
    printf("I'm %d philosopher!\n", ph->ph_num);
    while (1)
    {
        picking_up_forks(ph);
        eating(ph);
        putting_down_forks(ph);
        sleeping(ph);
        thinking(ph);
    }
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
        if(pthread_create(&(ph[i].thread), NULL, (void *)ph_routine, &ph[i]) != 0)
        {
            ft_putstr_fd("Error: failed to create thread\n", 2);
            return (FALSE);
        }
        pthread_detach(ph[i].thread);
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
    pthread_mutex_lock(&ph_info.someone_died_m);
    pthread_mutex_unlock(&ph_info.someone_died_m);
    //TODO: free all
    return (0);
}
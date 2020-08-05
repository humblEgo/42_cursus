#include "philo_one.h"

void    ft_putchar_fd(char c, int fd)
{
    write(1, &c, fd);
}

void    ft_putllnbr_fd(long long n, int fd)
{
        if (n >= 10)
            ft_putllnbr_fd(n / 10, fd);
        ft_putchar_fd(n % 10 + '0', fd);
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        if (n == -2147483648)
        {
            write(fd, "-2147483648", 11);
            return ;
        }
        write(fd, "-", 1);
        n *= -1;
    }
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd(n % 10 + '0', fd);
}

void    print_state(t_ph *ph, char *state)
{
    pthread_mutex_lock(ph->msg_m);
    ft_putllnbr_fd(get_cur_time() - *ph->start_time, 1);
    write(1, " ", 1);
    ft_putnbr_fd(ph->ph_num, 1);
    write(1, " ", 1);
    ft_putstr_fd(state, 1);
    if (state == DIED)
        return ;
    pthread_mutex_unlock(ph->msg_m);
}

void    print_ate_enough(t_ph_info *ph_info)
{
    pthread_mutex_lock(&ph_info->msg_m);
    ft_putstr_fd("All philosophers ate enough\n", 1);
}
#include "philo_one.h"

int         ft_strlen(char *s)
{
    int i;

    i = -1;
    while (s[++i])
        ;
    return (i);
}

void        ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}

long long   get_cur_time(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int         is_num_str(char *str)
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

void        ft_putchar_fd(char c, int fd)
{
    write(1, &c, fd);
}

void    ft_putnbr_fd(int n, int fd)
{
    int i;

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
    i = n % 10 + '0';
    write(1, &i, 1);
}

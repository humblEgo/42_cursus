#include "philo_one.h"

int     ft_strlen(char *s)
{
    int i;

    i = -1;
    while (s[++i])
        ;
    return (i);
}

void    ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}

long long   get_cur_time(void)
{
    struct timeval  tv;
    long long       res;

    gettimeofday(&tv, NULL);
    res = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (res);
}

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


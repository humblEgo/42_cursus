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
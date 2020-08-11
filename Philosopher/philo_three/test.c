#include "philo_three.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    sem_t *test;
    int     res;

    test = ft_sem_open("wow", 1);

    res = sem_wait(test);
    printf("wow1\n");
    res = sem_post(test);
    // printf("res: %d errno[0]: %d msg: %s\n", res,  errno, strerror(errno));
    // errno = 0;

    res = sem_close(test);
    res = sem_unlink("wow");
    printf("res: %d errno[1]: %d msg: %s\n", res, errno, strerror(errno));
    errno = 0;

    res = sem_wait(test);
    printf("res: %d errno[1.5]: %d msg: %s\n", res, errno, strerror(errno));
    errno = 0;

    printf("wow2\n");
    res = sem_post(test);
    printf("res: %d errno[2]: %d msg: %s\n", res, errno, strerror(errno));
    errno = 0;

    res = sem_unlink("wow");
    printf("res: %d errno[3]: %d msg: %s\n", res, errno, strerror(errno));
    errno = 0;

    return (0);
}
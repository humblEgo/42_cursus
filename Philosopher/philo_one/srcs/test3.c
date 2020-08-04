#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    struct timeval tv;
    long long   test;

    gettimeofday(&tv, NULL);
    test = tv.tv_sec * 1000 + tv.tv_usec / 1000;

    printf("%ld\n", tv.tv_sec);
    printf("%ld\n", tv.tv_usec);
    printf("%lld\n", test);
    return 0;
}
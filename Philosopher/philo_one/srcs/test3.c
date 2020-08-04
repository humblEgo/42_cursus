#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 쓰레드 함수
// 1초를 기다린후 아규먼트^2 을 리턴한다.
void *t_function(void *data)
{
    char a[100000];
    int num = *((int *)data);
printf("Thread Start\n");
    sleep(1);
printf("Thread end\n");
}

int main()
{
    pthread_t p_thread;
    int thr_id;
    int status;
    int a = 100;

printf("Before Thread\n");
    thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
    // 식별번호 p_thread 를 가지는 쓰레드를 detach
    // 시켜준다.
    pthread_detach(p_thread);
    pause();
    return 0;
}
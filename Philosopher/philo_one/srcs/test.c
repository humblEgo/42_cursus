#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
 
// 뮤텍스 객체 선언
typedef struct  s_mutex
{
    char *data;
    pthread_mutex_t *mutex_lock;
}               t_mutex;

struct timeval p1_time;
 
int g_count = 0;  // 쓰레드 공유자원.
 
void *t_function(void *arg)
{
    int i;
    t_mutex *test = (t_mutex *)arg;
    char* thread_name = test->data;
 
    pthread_mutex_lock(test->mutex_lock);
 
    // critical section
    g_count = 0;   // 쓰레드마다 0부터 시작.
    while (g_count < 10)
    {
        gettimeofday(&p1_time, NULL);
        printf("%d %ud %s COUNT %d\n", p1_time.tv_usec, (int)pthread_self(), thread_name, g_count);
        g_count++;  // 쓰레드 공유자원
        sleep(1);
    }
 
    pthread_mutex_unlock(test->mutex_lock);
    return (NULL);
}

int main()
{
    t_mutex test;
    t_mutex test2;
    pthread_t p_thread1;
    pthread_t p_thread2;

    int status;
    // 뮤텍스 객체 초기화, 기본 특성으로 초기화 했음
    test.mutex_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(test.mutex_lock, NULL);
    test2.mutex_lock = test.mutex_lock;
    test.data = "Thread1";
    test2.data = "Thread2";
    pthread_create(&p_thread1, NULL, t_function, (void *)&test);
    pthread_create(&p_thread2, NULL, t_function, (void *)&test2);
 
    // case 1
    pthread_join(p_thread1, NULL);
    pthread_join(p_thread2, NULL);
    pthread_detach(p_thread1);
    pthread_detach(p_thread2);

    // case 2
    // pthread_join(p_thread2, (void *)&status);
    // pthread_join(p_thread1, (void *)&status);
}
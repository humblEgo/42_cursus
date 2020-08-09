# Philosophers

Rules를 따르면서 철학자들이 스파게티 먹고 사색에 잠기도록 해주자. 한명이라도 죽으면 프로그램이 끝나므로 다 먹지 못할 것이다.

### Basic Rules

3개의 독립적인 프로그램을 만들어야한다. 3개의 프로그램은 아래의 기본룰을 따른다.
- 철학자는 테이블 주위에 앉아서 'eating, thinking, or sleeping' 중 하나의 동작을 한다.
- 한가지 동작 중엔 다른 동작을 할 수 없다. 
- 테이블은 둥근 형태이며 가운데에 스파게티 접시가 있다.
- 테이블 위에 포크가 올려져있다.
- 스파게티는 집기 어렵기 때문에, 철학자는 두 손에 각각 포크를 들고 스파게티를 집어야한다.
- 철학자는 결코 굶주리면 안된다.
- 모든 철학자는 먹어야한다.
- 철학자는 다른 이와 대화를 나누지 않는다.
- 철학자는 다른 철학자가 죽었는지 알 수 없다.
- 각 철학자는 식사를 마치면 포크를 내려놓고 수면을 취한다.
- 철학자는 수면을 마치면 사색에 잠긴다.
- 이런 상황은 철학자가 죽으면 끝난다.
- 각 프로그램은 동일한 옵션을 가지고 있어야한다.
    - number_of_philophers: 철학자와 포크의 개수. 이걸 생각하면, 철학자가 한명인 경우에는 식사가 불가해서 죽어버릴듯.
    - time_to_die: 철학자가 마지막 식사를 마치고 다음 식사를 마치기 전에 'time_to_die' milliseconds만큼 시간이 지나거나, 시뮬레이션을 시작하고 'time_to_die' milliseconds만큼 시간이 지나면, 철학자는 죽는다.
    - time_to_eat: 철학자가 먹기 시작하고 마치는데 걸리는 시간. 먹는 동안 철학자는 두개의 포크를 쥐고 있다. milliseconds 단위.
    - time_to_sleep: 철학자가 수면을 시작하고 마치는데 걸리는 시간. millisecond 단위.
    - [number_of_times_each_philosopher_must_eat]: 이 옵션인자는 선택적으로 주어진다. 만약 모든 철학자가 적어도 'number_of_times_each_philosopher_must_eat'시간만큼 먹었다면 시뮬레이션은 멈춘다. 만약 이 옵션이 설정되지 않았다면, 시뮬레이션은 철학자가 죽을 때에만 끝난다.
- 각 철학자는 1에서 'number_of_philosophers'까지의 번호를 받는다.
- 1번 철학자는 'number_of_philosophers'번 철학자 다음에 앉아있다. N번째 철학자는 N-1번째 철학자와 N+1번째 철학자 사이에 있다.
- 철학자의 상태변화는 하단과 같이 적혀져야한다. 이 때 'X'는 철학자의 번호로, 'timestamp_in_ms'는 milliseconds로 표현된 current timestamp로 갈음되어야한다.
    - timestamp_in_ms X has taken a fork
    - timestamp_in_ms X is eating
    - timestamp_in_ms X is sleeping
    - timestamp_in_ms X is thinking
    - timestamp_in_ms X died
- 한 철학자의 상태표시는 다른 철학자의 상태표시와 섞이거나 방해받으면 안된다.
- 철학자의 죽음과 그 죽음을 표시하는 사이에 10 ms 초과의 시간이 지나면 안된다.
- 다시한번 강조하건데, 철학자는 죽음을 피해야한다!

### Philosopher one

허용된 함수는 아래와 같다.
    - memset
    - malloc
    - free
    - write
    - usleep: sleep과 달리 microseconds를 인자로 받음. [man usleep](https://man7.org/linux/man-pages/man3/usleep.3.html)
    - gettimeofday: [man gettimeof]
    - pthread_create
    - phtread_detach
    - pthread_join
    - pthread_mutex_init
    - pthread_mutex_destroy
    - pthread_mutex_lock
    - pthread_mutex_unlock

Philosopher one을 만들기 위해 학습해야할 키워드는 아래와 같다.
- threads
- mutex

하나씩 학습해보자.
먼저 쓰레드는 **프로세스의 실행단위**이다. 따라서 쓰레드를 이해하려면 프로세스에 대한 이해가 선행되어야한다. 그리고 뮤텍스는 쓰레드의 동기화 방법의 종류 중 하나이다. 쓰레드를 이해하고 학습하자.

# 프로세스?

**프로세스는 프로그램이 실행되는 단위**이다. 또한 다른 말로 사용자가 작성한 **프로그램이 운영체제에 의해 메모리 공간을 할당받아 실행 중인 것**을 말한다. '실행 중인 것'이라는 말은 프로세스가 시작하고 종료하는 생명주기를 가지는 것을 내포한다. 
이미 minishell을 진행하며 많이 학습하였으므로 생략한다. 자세한 내용은 [위키](https://ko.wikipedia.org/wiki/%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4)와 [이 링크](https://bowbowbow.tistory.com/16)를 참고하자.

# 쓰레드?

![image](https://user-images.githubusercontent.com/54612343/88770779-441b0d80-d1b9-11ea-82a0-eeb9abd68a4f.png)


쓰레드는 프로세스 내에서 실제로 작업을 수행하는 주체를 의미한다. 모든 프로세스는 한 개 이상의 쓰레드가 존재하여 작업을 수행한다. 또한 두 개 이상의 쓰레드를 가지는 프로세스를 멀티쓰레드 프로세스라고 한다.

프로세스는 하나의 어드레스 공간을 가지고 있고, 쓰레드들은 자신을 관리하는 프로세스의 어드레스를 가지며 그 프로세스를 구성한다. 만약 서로 다른 쓰레드가 같은 프로세스를 구성하고 있다면, 그 프로세스에 할당된 메모리, 자원 등을 공유하게 된다. 이 관점에서 보면 프로세스는 쓰레드에 대한 일종의 컨테이너 역할을 한다고 할 수 있다.

한편 각 쓰레드별로 자신만의 스택과 레지스터를 가진다. (프로세스 자원을 공유하더라도 독립적인 작업을 수행해야하기 때문)

쓰레드는 프로세스처럼 실행, 준비, 대기 등의 실행 상태를 가지며, 실행 상태가 변할 때마다 **context switching**을 수행한다.

한 순간에 하나의 쓰레드만이 실행가능하다.

## 쓰레드의 장점
- 쓰레드는 프로세스보다 생성 및 종료시간, 쓰레드간 전환시간이 짧다.
- 쓰레드는 프로세스의 메모리, 자원등을 공유하므로 커널의 도움없이 상호간에 통신이 가능하다.

## 쓰레드 동기화 방법의 종류

- Mutex
    - mutex 는 Mutual exclusion의 악자로, 상호배제라는 뜻이다.  critical section을 가진 thread들의 running time이 서로 겹치지 않게, 각각 단독으로 실행되게 하는 기술이다.
    - **임계영역**에 들어가기 위해서는 이 뮤텍스를 가지고 있어야한다. 임계영역에 들어간 쓰레드가 뮤텍스를 이용해 임계영역에서 본인이 나올 때까지 다른 쓰레드가 못 들어오게 내부에서 뮤텍스(마치 자물쇠 잠그듯)로 배제시킨다.
- Semaphore
    - 뮤텍스와 비슷하지만 동시 접근 도익화가 아닌, **접근 순서 동기화**에 더 관련있다.
- Monitor
    - Mutex(Lock)와 Condition Variables(Queue라고도 함)을 가지고 있는 Synchronization 메카니즘이다.

- [참고](https://goodgid.github.io/What-is-Thread/)
- [참고2](https://elky.tistory.com/197)


## 쓰레드 교착상태


## 쓰레드 기아상태

- [참고](https://it-mesung.tistory.com/175)


#### 문제) 쓰레드 안에서 새로 분기된 쓰레드의 경우 에러가 나면 어떻게 프로그램을 잘 종료시킬 것인가?
#### 해결) 방법을 찾지못하여, 그냥 쓰레드를 모두 메인쓰레드에서 분기되도록 구조를 바꾸었다.

#### 문제) 메인스레드 종료전에 모든 뮤텍스를 파괴시키려고 할 때 undefined behavior가 걱정된다.
#### 해결) 실험결과 undefined behavior는 다시 뮤텍스를 사용하려고 할 때 발생되는 것으로 보인다.

#### 문제) 메인쓰레드 종료전에 모든 뮤텍스를 파괴시키려고 할 때 무한대기 상태에 빠진다.
#### 해결) 초기화되지 않은채로 뮤텍스로 쓰인 pthread_t 구조체가 있었다. 초기화를 해주니 destroy도 가능했음.
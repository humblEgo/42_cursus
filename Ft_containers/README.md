# Ft_containers

Reimplement STL containers in C++98 version.



c++ 컨테이너를 직접 구현해야한다. iterator가 있다면, 그 또한 구현해야한다. 단, `get_allocator` 함수는 구현할 필요 없다.

우리가 Mandantory part에서 구현해야할 컨테이너는 아래 5가지이다.

- List
- Vector
- Map
- Stack
- Queue

보너스에서는 아래 4가지를 구현해야한다.

- Deque
- Set
- Multiset
- Multimap



우선 cpp 모듈을 공부할 때 공부한 것을 상기해보자.

- C++에서 말하는 컨테이너는 같은 타입의 여러 객체를 저장하는 일종의 집합이라 할 수 있다. 

- 컨테이너는 클래스템플릿으로 컨테이너 변수를 선언할 때 컨테이너에 포함할 요소의 타입을 명시할 수 있다. 

- 컨테이너에는 복사 생성과 대입을 할 수 있는 타입의 객체만을 저장할 수 있다. 그리고 요소의 추가 및 제거를 포함한 다양한 작업을 도와주는 여러 멤버 함수를 포함하고 있다.

- 특히 C++에서 제공하는 STL에서는 자료를 저장하는 방식과 관리하는 방식에 따라 크게 세 가지 유형으로 구분된다.

  1. 시퀀스 컨테이너: 데이터를 선형으로 저장하며, 특별한 제약이나 규칙이 없는 가장 일반적인 컨테이너

     - [vector](https://blockdmask.tistory.com/70): 가변 크기의 배열을 일반화한 클래스
     - [deque](https://modoocode.com/223): 앞 뒤 모두 입력 가능한 큐 클래스
     - [list](https://blockdmask.tistory.com/76): 빠른 삽입/삭제 가능한 리스트 클래스

  2. 연관 컨테이너: 데이터를 일정 규칙에 따라 조직화하여 저장하고 관리하는 컨테이너

     - set: 정렬된 순서로 값을 저장하는 집합 클래스. key값이 중복되지 않는다.내부에 원소를 추가할 때 정렬된 상태를 유지하며 추가된다.
     - multiset: set과 거의 동일하지만 key값이 중복될 수 있다.
     - map: key-value 쌍을 저장하는 맵 클래스
     - multimap: map과 거의 동일하지만 key값이 중복될 수 있다.

  3. 컨테이너 어댑터: 간결함과 명료성을 위해 인터페이스를 제한한 시쿼스나 연관 컨테이너의 변형 (단, 반복자를 지원하지 않으므로 STL 알고리즘에서는 사용할 수 없다.)

     - stack: 스택을 일반화한 클래스

     - queue: 큐를 일반화한 클래스

     - priority_queue: 우선순위에 따라 push하고 pop한다!

이제 [cpluscplus.com 레퍼런스](https://www.cplusplus.com/reference/stl/)를 보면서 세부사항을 파악해보자. bash를 구현할 때 bash reference를 참고했던 것처럼, 공식문서가 짱이다.

Member map을 보면 각 컨테이너별로 중복되는 기능이 많은 것을 확인할 수 있다. 얼마나 중복없이 효율적으로 코딩하느냐가 관건일 것 같다. 테스트 케이스도 내가 제공해야하므로 TDD로 진행하면 더할나위 없을듯하다.



# vector

https://www.cplusplus.com/reference/vector/vector/

친절하게도 Member type과 Member functions가 나와있다. C++98에 해당하는 것들을 구현하면 된다.

원형: `template < class T, class Alloc = allocator<T> > class vector; // generic template`

인자로는 아래 두가지를 받는다.

1. `T`: Type of the elements
2. `Alloc`: Type of the allocator object used to define the storage allocation model.

[모두의코드](https://modoocode.com/178) 에서처럼 예제를 가져와서 실험해가며 구현하자.

<details><summary>문제: 처음에 begin()을 통해 얻은 첫번째 iterator가 vector에 새로운 인자를 insert를 할 때마다 유효하지 않게 된다.</summary>
<p>
  우선 vector의 동작 방식을 이해할 필요가 있다. vector는 가변배열이긴하지만 인자가 추가될 때마다 새로 공간을 할당해서 그 공간에 값을 채워넣는 식으로 동작하지 않는다. 이런식으로 동작하면 인자가 잦게 추가되는 경우마다 공간을 할당하고 값을 채워넣어야하므로 매우 비효율적이다. 그럼 어떻게 해야 효율적으로 처리할 수 있을까? vector는 미리 일정한 메모리공간을 할당해두고, 인자가 추가되었을 때 미리 할당해둔 메모리에 값을 넣는 전략을 쓴다. 물론 이 경우에도 잦은 insert 등으로 미리 할당해둔 메모리를 넘는 사이즈로 vector가 확장되었을 경우엔, 메모리에 재할당하고 그 메모리에 기존 vector의 데이터들을 복사하는 식으로 작동할 수 밖에 없다.

  자 그럼 위 문제는 왜 일어난 것일까? 바로 내가 구현해둔 코드에서는 아래처럼 새로 추가된 인자의 사이즈만큼만 메모리를 할당해서 쓰도록 구현되어있었기 때문이다. 이 경우 insert할 때마다 메모리 전체의 재할당 및 복사가 이뤄지고 결국 기존에 iterator가 가리키고 있던 메모리주소는 유효하지 않은 메모리 주소가 된다.
  ```
  if (new_size > _cap)
        reserve(new_size);
  ```
  아래처럼 코드를 수정하여 미리 더 많은 공간을 할당해둘 수 있도록 하였다.
  ```
  if (new_size > _cap)
    {
  			reserve(_cap / 2);
    }
  ```

</p>
</details>



# Allocator

https://www.cplusplus.com/reference/memory/allocator/

원형: `template <class T> class allocator;`

Allocator는 특히 STL 컨테이너들의 메모리 모델을 정의하는 클래스이다. 모든 기초 컨테이너들이 마지막 인자를 입력하지 않으면 `default allocator`가 사용된다.

대부분의 경우 new나 delete를 쓰기만 해도 충분할텐데 왜 allocator를 쓸까? [이 링크](https://kldp.org/node/109031)의 문답이 설득력 있는 것 같다. STL 클래스별로 allocation 정책을 자유자재로 적용하기 위함이다! 게임이나 웹서버에서 힙 대신 메모리풀을 이용하는 용도로 allocator를 쓰곤 한다고 한다.

참고로 메모리풀은 이미 결정된 메모리 영역을 대량으로 확보한 후 그 확보한 메모리 영역만을 사용하여 메모리에 데이터를 할당하는 방법이다. 메모리를 한번 할당한 후 한번에 해제하기 때문에 잦은 메모리 할당 해제로 인한 부하 및 메모리 단편화 문제를 해결할 수 있다.

[C++ Standard Allocator, An Introduction and Implementation](https://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement)을 보면 더 자세하게 확인할 수 있다.

우리는 딱히 구현할 필요 없다. 가져다 쓰자!


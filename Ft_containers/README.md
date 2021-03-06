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

  1. 시퀀스 컨테이너: 데이터를 선형으로 저장한다. 즉, 순서를 유지한다. 특별한 제약이나 규칙이 없는 가장 일반적인 컨테이너. 

     - [vector](https://blockdmask.tistory.com/70): 가변 크기의 배열을 일반화한 클래스
     - [deque](https://modoocode.com/223): 앞 뒤 모두 입력 가능한 큐 클래스
     - [list](https://blockdmask.tistory.com/76): 빠른 삽입/삭제 가능한 리스트 클래스. C에서의 더블링크드 리스트 비슷.

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



# Allocator

https://www.cplusplus.com/reference/memory/allocator/

원형: `template <class T> class allocator;`

Allocator는 특히 STL 컨테이너들의 메모리 모델을 정의하는 클래스이다. 모든 기초 컨테이너들이 마지막 인자를 입력하지 않으면 `default allocator`가 사용된다.

대부분의 경우 new나 delete를 쓰기만 해도 충분할텐데 왜 allocator를 쓸까? [이 링크](https://kldp.org/node/109031)의 문답이 설득력 있는 것 같다. STL 클래스별로 allocation 정책을 자유자재로 적용하기 위함이다! 게임이나 웹서버에서 힙 대신 메모리풀을 이용하는 용도로 allocator를 쓰곤 한다고 한다.

참고로 메모리풀은 이미 결정된 메모리 영역을 대량으로 확보한 후 그 확보한 메모리 영역만을 사용하여 메모리에 데이터를 할당하는 방법이다. 메모리를 한번 할당한 후 한번에 해제하기 때문에 잦은 메모리 할당 해제로 인한 부하 및 메모리 단편화 문제를 해결할 수 있다.

[C++ Standard Allocator, An Introduction and Implementation](https://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement)을 보면 더 자세하게 확인할 수 있다.

우리는 딱히 구현할 필요 없다. 가져다 쓰자!





## Iterator

https://en.cppreference.com/w/cpp/iterator/iterator



Iterator_traits의 멤버데이터

- `difference_type` - a signed integer type that can be used to identify distance between iterators
- `value_type` - the type of the values that can be obtained by dereferencing the iterator. This type is `void` for output iterators.
- `pointer` - defines a pointer to the type iterated over (`value_type`)
- `reference` - defines a reference to the type iterated over (`value_type`)
- `iterator_category` - the category of the iterator. Must be one of [iterator category tags](https://en.cppreference.com/w/cpp/iterator/iterator_tags).





# vector

https://www.cplusplus.com/reference/vector/vector/

친절하게도 Member type과 Member functions가 나와있다. C++98에 해당하는 것들을 구현하면 된다.

원형: `template < class T, class Alloc = allocator<T> > class vector; // generic template`

인자로는 아래 두가지를 받는다.

1. `T`: Type of the elements
2. `Alloc`: Type of the allocator object used to define the storage allocation model.

[모두의코드](https://modoocode.com/178) 에서처럼 예제를 가져와서 실험해가며 구현하자.

 

#### 문제: 처음에 begin()을 통해 얻은 첫번째 iterator가 vector에 새로운 인자를 insert를 할 때마다 유효하지 않게 된다 

#### 해결:

우선 vector의 동작 방식을 이해할 필요가 있다. vector는 가변배열이긴하지만 인자가 추가될 때마다 새로 공간을 할당해서 그 공간에 값을 채워넣는 식으로 동작하지 않는다. 이런식으로 동작하면 인자가 잦게 추가되는 경우마다 공간을 할당하고 값을 채워넣어야하므로 매우 비효율적이다. 그럼 어떻게 해야 효율적으로 처리할 수 있을까? vector는 미리 일정한 메모리공간을 할당해두고, 인자가 추가되었을 때 미리 할당해둔 메모리에 값을 넣는 전략을 쓴다. 물론 이 경우에도 잦은 insert 등으로 미리 할당해둔 메모리를 넘는 사이즈로 vector가 확장되었을 경우엔, 메모리에 재할당하고 그 메모리에 기존 vector의 데이터들을 복사하는 식으로 작동할 수 밖에 없다.

자 그럼 위 문제는 왜 일어난 것일까? 바로 내가 구현해둔 코드에서는 아래처럼 새로 추가된 인자의 사이즈만큼만 메모리를 할당해서 쓰도록 구현되어있었기 때문이다. 이 경우 insert할 때마다 메모리 전체의 재할당 및 복사가 이뤄지고 결국 기존에 iterator가 가리키고 있던 메모리주소는 유효하지 않은 메모리 주소가 된다.

  ```cpp
  if (new_size > _cap)
        reserve(new_size);
  ```

  아래처럼 코드를 수정하여 미리 더 많은 공간을 할당해둘 수 있도록 하였다.

  ```cpp
  if (new_size > _cap)
    {
    		if (new_size < cap * 2)
  					reserve(cap*2);
  			else
  					reserve(new_size);
    }
  ```



## List

https://en.cppreference.com/w/cpp/container/list

iterator 유형이 bidirectional로 바뀌었다. 이에 유의해서 코딩할 것.

[리스트 소스코드](http://cs.brown.edu/~jwicks/libstdc++/html_user/stl__list_8h-source.html) 를 참고하면 begin()은  `return this->_M_impl._M_node._M_next;`처럼 구현되어있고, end()는 `return this->_M_impl._M_node;`처럼 구현되어 있는 것을 확인할 수 있다. 내부적으로 가장 마지막 node 주소를 저장해두되 그 node의 next는 begin node와 연결되도록 하여 일종의 **환형태**로 연결하는 것이 좋겠다.



## Stack

https://en.cppreference.com/w/cpp/container/stack

컨테이너 어댑터에 속해있는 Stack! 왜 어댑터라는 표현이 붙었냐면, vector, deque, list container에 붙여서 붙인 컨테이너를 기반으로 stack과 같이 작동하도록 지원해주기 때문이다.

마침 List를 구현해둔만큼 디폴트로는 List로 기능을 구현시키고, 다른 컨테이너도 받을 수 있도록 하자.

Stack이 감싸고 있는 컨테이너에 접근할 수 있도록 friend 키워드를 써서 연산자를 오버로딩해보자. [이 링크](https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60205572356&proxyReferer=https:%2F%2Fwww.google.com%2F) 참고!



## Map

https://en.cppreference.com/w/cpp/container/map

템플릿 인자만해도 4개.. 굉장히 복잡해보인다. 
일단 value_type에 `std::pair<const Key, T>`를 쓰는 것을 주목해보자. 

https://en.cppreference.com/w/cpp/utility/pair

이 pair 데이터형으로 key 와 value를 짝지어넣을 수 있다.



그리고 이 pair 자료들은 어떻게 엮이는가? 보통 [레드-블랙빈 트리](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)로 내부구현된다고 하는데 흠.. 굳이 이 정도로 구현할 필요는 없을 것 같다. 그냥 일반적인 Binary search tree로 구현해보자.



#### Binary serach tree?

이진 탐색 트리는 이진 트리 기반의 탐색을 위한 자료 구조이다. 아래 4가지 조건을 가지고 있다.

1. 모든 노드의 키는 유일하다. 
   여기서 키는 노드 안에 들어있는 데이터 값을 말하며, 중복된 데이터를 갖는 노드는 없다는 걸 뜻한다.
2. 왼쪽 서브 트리의 키들은 루트의 키보다 작다.
3. 오른쪽 서브 트리의 키들은 루트의 키보다 크다.
4. 왼쪽과 오른쪽의 서브 트리도 이진 탐색트리이다.

erase 구현이 상당히 복잡한데, [이 링크](https://mattlee.tistory.com/30)와 sanam, hbrulin 씨 등의 깃헙 코드를 참고하였다.
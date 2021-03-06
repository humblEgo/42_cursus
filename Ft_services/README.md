# FT_SERVICE

본 프로젝트는 쿠버네티스를 활용하여 파드별로 도커를 통해 독립적인 서비스를 띄우는 42seoul 과제입니다.
도커허브나 NodePort 서비스를 사용하지 못하는 등의 제약하에 구현되었습니다.

아래는 본 프로젝트를 하며 학습한 내용을 메모한 것입니다.

# Kubernetes

## 파드

파드 안에는 하나의 독립적인 서비스를 구동할 수 있는 컨테이너를 1개 or 여러개 가지고 있다. 이 컨테이너들은 각자 port를 하나 이상 가질 수 있는데, 한 파드에서 컨테이너끼리 port가 중복될 순 없다. 

파드가 생성될 때에는 IP가 자동으로 할당되는데, 쿠버네티스 클러스터내에서만 접근 가능하며, 외부에서는 접근이 불가능하다. 또한 파드가 생성될 때마다 변경되는 휘발성을 가지고 있다.

### 라벨
라벨은 파드 뿐 아니라 모든 오브젝트에 달 수 있는데 파드에서 가장 많이 활용한다. 라벨 덕분에 파드들을 나누어서 자신이 원하는 파드들만 골라서 편하게 관리할 수 있다. key와 value로 구성되어있다.

### Node Schedule

파드를 만들 때 어느 노드에 위치시킬지를 1) 수동으로 선택하거나 2) 노드 스케쥴러의 판단하에 선택하는 방법이 있다. 노드 스케쥴러에 yaml에 resource-request로 파드에 필요한 자원 정보를 적어주면 이에 맞는 노드에 파드를 생성시키는 것이다.

## 서비스

파드는 기본적으로 휘발성을 가지고 있다. 어떤 장애가 나면 파드가 삭제되고 재생성되도록 되어있기 때문이다. 재생성될 때마다 파드는 IP를 할당받긴 하지만 이 IP가 계속 바뀌므로 접근이 어렵다.
이런 문제를 해결하기 위해 존재하는 오브젝트가 서비스이다.
서비스는 파드에 접근할 수 있도록 해주는 방식에 따라 Cluster IP, NodePort, Load Balancer 로 타입을 나눌 수 있다.
참고로 어떤 타입이든 간에 서비스에는 기본적으로 ClusterIP가 할당된다.

1. ClusterIP

![image](https://user-images.githubusercontent.com/54612343/88621511-a1409180-d0db-11ea-8928-c211b6e62790.png)

서비스의 디폴트 타입은 ClusterIP이다. CluseterIP의 포트와 연결된 타겟포트가 열려있는 파드들에 접근할 수 있다. 이 때 타겟포트가 열려있는 파드는 단수가 아니라 다수일 수 있고, 이 경우 서비스가 트래픽을 분산해서 파드에 전달해준다.

외부에서 접근할 수 없고 클러스터 내부에서만 접근할 수 있으므로, **인가된 사용자(운영자)**가 **내부 대시보드**작업을 하거나 **Pod의 서비스 상태 디버깅**을 할 때 쓴다.

2. NodePort

![image](https://user-images.githubusercontent.com/54612343/88621664-01cfce80-d0dc-11ea-8295-128a2578952e.png)

기본적으로 ClusterIP와 동일한 기능을 가지고 있고, NodePort의 특징들을 추가로 가지고 있다. NodePort는 모든 Node에 포트를 할당한다(특정 파드에만 할당하는게 아니다!!)

한편 externalTrafficPolicy라는 재밌는 옵션이 있다. 위 이미지에서 Node1를 통해 서비스에 트래픽을 보내더라도 서비스가 Node2에 트래픽을 보낼 수 있다. 왜냐면 서비스 입장에서는 그냥 자신에게 연결된 파드에게 트래픽을 보내는 것이기 때문이다. 이 때 서비스에 `externalTrafficPolicy: Local`로 옵션을 주면, 특정 노드로 접근한 트래픽은 그 노드 위에 있는 파드로만 전달한다. minikube를 쓰면 노드를 마스터노드, 워킹노드로 나누는게 아니라 하나만 쓰므로 별 이슈는 없다.

NodePort는 물리적인 호스트에 IP를 통해서 접근이 가능한 특징을 가지고 있다. 대부분 호스트 IP는 보안적으로 내부에서만 접근 가능하도록 쓰이므로, 실제 서비스에서 외부에 연결하는 용도로 쓰이지는 않는다. 굳이 쓰는 경우엔 간단한 데모를 외부에서 시연하는 경우에 중계기에 포트포워딩해서 쓰는데 이럴 때 임시적으로 NodePort를 뚫어놓고 쓰는 정도라고 한다.
참고로 42seoul 프로젝트에서는 2020년 7월 기준으로 프로젝트 요구사항이 달라져서 NodePort는 쓸 수 없게 되었다.

3. Load Balancer

![image](https://user-images.githubusercontent.com/54612343/88623359-c505d680-d0df-11ea-9063-1bc312997379.png)

NodePort가 ClusterIP의 특징을 그대로 가지고 있었던 것처럼, Load Balancer type의 서비스도 NodePort의 특징을 그대로 가지고 있다. 그리고 추가적으로 로드밸런서가 생겨서 각각의 노드에 트래픽을 분산시키는 역할을 한다. 문제는 로드밸런서가 있다고 해서 IP가 자동으로 할당되는 것이 아니라, 플러그인으로 외부에서 접근 가능한 IP(External IP)를 만들어줘야한다. GCP, AWS, Azure, OpenStack 같은 클라우드에는 이 플러그인 기능을 잘 갖추고 있다(물론 오픈스택은 따로 셋팅해줘야할테지만~). 42seoul 프로젝트에서는 metalLB을 활용하여 베어메탈에서 External IP를 로드밸런서에 할당한다.

실제적으로 외부에 서비스를 노출시키려면 로드밸런서를 써야한다. 그래야 내부 IP를 노출시키지 않고 외부에 IP를 노출시킬 수 있기 때문이다.
한편 이 프로젝트에서는 metalLB의 layer 2 모드를 사용하여 `EXTERNAL_IP`를 각 쿠버네티스 서비스에 할당했는데, 이 경우엔 하나의 노드에서만 서비스에 액세스 할 수 있기 떄문에 제한적이다. 만약 여러개의 노드를 활용하는 상용환경이라면 BGP 모드를 사용하는 것이 가장 좋다고 한다.

[참고1](https://www.inflearn.com/course/%EC%BF%A0%EB%B2%84%EB%84%A4%ED%8B%B0%EC%8A%A4-%EA%B8%B0%EC%B4%88)
[참고2](https://www.objectif-libre.com/en/blog/2019/06/11/metallb/)

## 볼륨

- emptyDir
    - 컨테이너끼리 데이터를 공유하기 위해서 사용하는 볼륨임. 최초 볼륨이 생성될 때 항상 볼륨이 비어있으므로 emptyDir로 명명되었다.
    - 같은 파드에 속한 서로 다른 컨테이너들이 같은 path를 volume으로 두고 mount하여 활용할 수 있다.
    - Pod 생성시 만들어지고 삭제시 없어짐.
- hostPath
    - 이름 그대로 파드들이 올라가있는 호스트인 노드에 볼륨을 만들고, 그 노드에 올라가있는 각 파드들이 마운트할 수 있다.
    - 파드의 소멸, 재생성 되는지 여부와 상관없이 노드에 존재한다. 하지만 한 파드가 사라진 다음 해당 노드에 생성될거라는 보장이 없다(기존 노드에 장애가 생기거나 자원이 부족하거나 등등의 이유로..). 때문에 노드를 추가할 때마다 기존 노드에 있는 볼륨과 마운트해줘야하는 번거로움이 있다.(그러니까 기존 노드에 대한 경로가 있어야한다.)
    - 파드 자신이 할당되어있는 호스트의 데이터를 읽거나 쓸 경우에 쓴다.
- PVC / PV
    - 파드에 영속성있는 볼륨을 제공하기 위한 개념이다. 영속성있는 볼륨은 어떻게 만들어 쓰는가? 먼저 AWS 같은 클라우드 업체나 storageOS같은 서드파티 솔루션으로 볼륨을 만들고 `Persistent Volume(이하 PV)`이라고 정의해서 쓸 수 있다. 근데 이 때 파드는 `PV`에 바로 연결되지 않고 `Persistent Volume Claim`을 통해 연결된다.
    ![image](https://user-images.githubusercontent.com/54612343/88632531-a78c3900-d0ee-11ea-9bb9-b07aef5267d9.png)
    - 왜 `PV`에 바로 연결하는게 아니라 `PVC`를 거쳐서 연결하는 걸까? 쿠버네티스는 볼륨 사용에 있어서 User 영역과 Admin 영역으로 나누었다. User는 파드에 서비스를 만들고 배포하는 관리자이고, admin은 이에 필요한 볼륨을 관리하는 사람들이다. User는 yaml을 통해 필요한 용량, accessMode 등을 볼륨에 요청한다. 그럼 Admin에 속하는 다양한 볼륨제공자들이 이에 맞추어 볼륨을 제공한다. 결국 쿠버네티스는 `PVC`이라는 하나의 양식으로 볼륨을 요청하면서도 다양한 볼륨을 가져다쓸 수 있게되는 것이다.

----

#### 문제) metalLB에 의해 할당된 `EXTERNAL_IP`로 접속할 때 어떤 경우엔 잘 접속되고, 어떤 경우엔 잘 안된다.
#### 해결) metalLB에서의 IP range를 `minikube IP` 기준으로 설정해준다.

본 프로젝트는 metalLB의 Layer 2 mode를 활용하였다. metalLB로 생성된 `EXTERNAL_IP`로 서비스에 액세스하면, metalLB 컨트롤러가 이 `EXTERNAL_IP`의 MAC주소를 찾기 위해 ARP 요청을 전송하고, 클러스터의 각 노드에 설치되어있는 metalLB 스피커가 layer2 주소, 즉 MAC 주소로 응답한다.

이 경우 metalLB 및 노드 IP에 제공하는 주소 범위는 동일한 서브넷에 있어야한다. minikube를 이용했을 때, 활용하는 노드는 하나이고 이 노드의 주소는 `minikube IP`이다. 그러니 처음부터 metalLB의 configmap yaml파일에 `192.168.99.100 - 192.168.99.110`처럼 명시적으로 IP pool을 고정시켜 설정해놓으면, `minikube IP`의 서브넷과 IP pool의 서브넷이 일치할 때는 'EXTERNAL IP'로 잘 접속되고, 일치하지 않을 때는 접속되지 않는 것이다. 따라서 **`minikube IP`가 생성되고 나면, 이를 바탕으로 metalLB의 IP pool을 설정하자.** 

구체적으로 말하자면, [요 링크](https://medium.com/@emirmujic/istio-and-metallb-on-minikube-242281b1134b)에 따르면 로컬에서는 `minikube IP`를 IP pool range의 시작으로 활용하는 것 같다. *사실 metalLB 자체가 그리 오래된게 아니어서 [환경에 따라 다르고](https://metallb.universe.tf/concepts/) 쓰는 사람 마음인 것 같긴 하다. 작동하게만 하자.*


[참고1](https://metallb.universe.tf/concepts/)
[참고2](https://medium.com/@shoaib_masood/metallb-network-loadbalancer-minikube-335d846dfdbe)
[참고3](https://m.blog.naver.com/PostView.nhn?blogId=sbd38&logNo=50191972929&proxyReferer=https:%2F%2Fwww.google.co.kr%2F)
[참고4](https://metallb.universe.tf/concepts/)
[참고5](https://medium.com/@emirmujic/istio-and-metallb-on-minikube-242281b1134b)



----


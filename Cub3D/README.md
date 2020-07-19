# Cub3D
My first RayCaster with miniLibX

이 프로젝트는 42seoul 커리큘럼에 포함되어있습니다. 42seoul의 norm과 제약사항(ex for문 쓸 수 없음, 한 함수는 25줄을 넘을 수 없음, 허용되는 함수만 쓸 것 등등)에 따라 코딩되어 있습니다.
프로젝트의 내용은 [링크](https://github.com/moon9ua/42_seoul/wiki/2.-cub3D#cub3d)에서 확인할 수 있습니다.

## 구현내용

결과적으로 구현된 내용은 아래와 같습니다.

1. cub3D파일에 맵파일을 인자로 전달하면 그 내용에 따라 그래픽이 출력됨.

    - 천장과 바닥에 texture 대신 단일컬러를 설정한 경우

    ![녹화_2020_06_24_10_14_27_257](https://user-images.githubusercontent.com/54612343/87877836-9458d980-ca1b-11ea-8a32-61891122e326.gif)

    - 천장과 바닥에 texture를 설정한 경우

    ![녹화_2020_06_24_10_13_34_480](https://user-images.githubusercontent.com/54612343/87877857-b4889880-ca1b-11ea-90ef-69accc43f343.gif)

2. `--save` 옵션을 주면 시작시 플레이어 시점이 bmp형식으로 screenshot이 생성됨.
3. W,A,S,D키를 통해 이동가능. left arrow, right arrow 키를 통해 시점회전 가능, ESC 키를 통해 종료
4. 벽, 아이템 충돌 구현

## 설치
- Mac
    1. `cd cub3D_macOS`
    2. `make`

- Ubuntu
    1. `cd cub3D_ubuntu`
    2. `make`

`./cub3D map_file` 로 실행!

## 비고
- map의 유효성 검사 구현은 TDD 방식으로 진행했으며, 당시 사용한 테스트파일을 이용한 [cub3D_map_tester](https://github.com/humblEgo/cub3D_map_tester)를 구현하여 42seoul 커뮤니티에 배포하였습니다.
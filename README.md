# KUboard
### C 언어로 만든 타자연습 게임!

## 제작자
김지환 고영빈 나예담 김현지   

---
## 구현한 주요 기능 및 구현 기술
- 단어 타자 연습
  - 영어 문자열 랜덤 생성   
    ```c
    rand() 이용해서 랜덤 행 번호 선택 후 enWords.txt에서 fgets() 로 행 전체 읽어오기   
    ```
  - 장애물이 캐릭터에 부딪힐 때마다 새 문자열 출력
    ```c
    <time.h> 의 clock_t 형 변수 이용. 특정 시각마다 장애물 위치 이동
    캐릭터와 장애물의 y 좌표가 겹치면 장애물 처음 위치로 이동   
    ```
  - 사용자가 똑같은 문자열 입력하면 점수 획득 및 새 문자열 출력
    ```c
    strcmp() 로 비교
    ```

- 난이도 조정 기능
  - 장애물 다가오는 속도에 따라 초급, 증급, 고급 난이도
    ```c
    선택된 int *level 포인터를 매개변수로 받아 장애물 이동 속도 조절과 문자열 길이로 난이도 변경
    ```
  - 난이도 선택 메뉴
    
  - 일정 시간 성공하면 다음 레벨로 이동   
    ```c
    <time.h>의 clock_t 로 시간 측정 후 *level 변경
    ```


- 메뉴 화면
  ```c
  콘솔 좌표 지정
  ```
- 키보드 방향키 기반 메뉴 선택
  ```c
  함수 제작
  void keySelectBtn(int* currentCursorY, int n, int X, int Y, int d); //현재 커서 Y위치 currentCursorY, 메뉴 개수 n, 1번 메뉴의 좌표 X, Y, 메뉴 간의 좌표 차 d
  ```
- 메인 화면(캐릭터, 바닥, 장애물)   
  ```c
  캐릭터, 바닥, 장애물, 단어 각각 draw~() 함수로 분리해서 콘솔에 출력
  ```
- 캐릭터 달리는 효과 및 장애물 이동
  ```c
  일정 시간 마다 캐릭터 다리 부분 변경, 장애물 앞으로 이동 (system("cls")를 쓰면 화면 깜빡임이 심해서 이전 좌표값에 공백 출력)
  ```
- 아이템 기능
  ```c
  키보드 '1' 누르면 작동. 각각 알맞은 아이템 효과
  ```
- 배경음악 재생
  ```c
  PlaySound(pszSound, hmod, fdwsound); (파일 경로, 실행 가능 파일의 핸들, 재생 옵션 플래그)
  <Window.h>, <mmsystem.h>, #pragma comment(lib."winmm.lib") 선언 필요.
  ```
- 랭킹 저장 및 정렬
  ```c
  fgets, fputs, fscanf, fprintf
  사용자, 점수 구조체에 넣은 후 bubble sort로 정렬 구현.
  ```
- 콘솔 색깔
  ```c
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ) 이용해서 color() 함수 제작
  <Window.h>
  ```

---
## 프로그램 실행 화면
### 1. 메인 메뉴   
![image](https://user-images.githubusercontent.com/67897841/121388744-b4242380-c986-11eb-999a-0cc88cb6a25d.png)
### 2. 랭킹 확인
![image](https://user-images.githubusercontent.com/67897841/121388946-de75e100-c986-11eb-8c5d-b16c65d42544.png)
### 3. 인게임 화면
![image](https://user-images.githubusercontent.com/67897841/121389102-07967180-c987-11eb-9d2a-ae30c38a1909.png)
### 4. GAME OVER 화면
![image](https://user-images.githubusercontent.com/67897841/121389142-13823380-c987-11eb-9fb8-eaf5e3aa05b0.png)


---
## 프로그램 기능 별 함수 구분 및 데이터 흐름도   
![image](https://user-images.githubusercontent.com/67897841/121382689-d10a2800-c981-11eb-9192-c6ecf328fe82.png)
![image](https://user-images.githubusercontent.com/67897841/121382699-d36c8200-c981-11eb-9a3a-3e96291b22b9.png)


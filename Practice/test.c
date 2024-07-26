#include <pthread.h>                   // POSIX 스레드(pthread) 라이브러리를 사용하기 위한 헤더 파일
                                        // pthread_t(구조체), pthread_create() ,pthread_join()
#include <stdlib.h>                     // 다양한 유틸리티 함수와 메모리 관리 함수, 난수 생성 함수 등을 제공 - abort(), exit() 사용
#include <unistd.h>                     // POSIX 운영 체제 API를 사용 - sleep() 사용
#include <stdio.h>                     // 입출력 함수를 제공하는 헤더 파일 - printf(), fflush(), stdout 사용

int myglobal = 3;                  // 각 스레드에서 동시에 접근하는 과정을 보여주기 위해 선언
                              // C 언어에서는 전역변수의 별도 초기화가 없을 시 0으로 초기화됨
                              // 동기화 과정이 없기 때문에 예측 불가한 결과가 생성됨

// 스레드 코드                         
void *thread_function(void *arg){       // void * 를 사용하면 다양한 타입으로 캐스팅이 가능하다
                                        // 스레드 함수의 반환 값은 스레드가 실행된 결과를 나타내며
                                        // 이 값을 다른 곳에서 사용하기 위해서는 스레드 함수가 반환하는 값의 타입을 알아야 한다
                                        // 현재 코드에서는 arg 변수가 사용되지 않았지만 사용
	int i, j;
	for(i = 0; i < 20; i++){
		j = myglobal;
		j = j + 1;                // 변수를 스레드에서 수정하는 동안 출력
		printf("x");
		fflush(stdout);           // fflush() - 표준 입출력 버퍼를 비우는 함수
                              // stdout - 출력 버퍼를 사용하여 데이터를 저장
                              // 즉 출력 버퍼를 비워 o, x 가 번갈아 가면서 나오게 하려고 선언
                              // 만약 선언되지 않았다면 출력 버퍼에 문자열이 쌓이면서 한꺼번에 출력될 수 있음
		sleep(1);                 // 해당 스레드를 1초동안 blocked 상태로 만듬
		myglobal = j;
	}
	return NULL;
}

// main 스레드 코드
int main(void){
	pthread_t mythread;           // p스레드 타입의 변수 mythread를 선언
	int i;                       // 반복문을 위한 변수

	if(pthread_create (&mythread, NULL, thread_function, NULL)){     //스레드를 생성 명령문을 통해 함수가 제대로 실행되었는지를 확인하는 과정
    // 1. 스레드의 식별자  2. p스레드 속성 구조체  3. 스레드에서 실행될 함수의 주소  4. 스레드에 전달할 인자
    // 스레드 생성에 실패하는 경우 //
    // 1. 해당 프로세스가 사용가능한 자원이 한계치가 온 경우
    // 2. 다른 프로세스 또는 스레드에서 자원을 점유한 경우
    // 3. 스레드 생성 도중 프로세스가 종료되는 경우
		printf("ldquo; error creating thread.");                      // 스레드가 정상적으로 생성되었다면 반환되는 값은 0
                                                                  // 만약 생성되지 못 했다면 0 이외의 값을 반환
		abort();                             // 프로그램을 즉시 종료시키는 함수                         
	}                                     // 프로그램의 상태는 정상적으로 종료되지 않았음을 알리는 비정상 종료 코드(abort code)와 함께 운영 체제에게 반환

	for(i = 0; i < 20; i++){
		myglobal = myglobal + 1;             // 메인 스레드에서 수정하는 동안 출력
		printf("o");
		fflush(stdout);
		sleep(1);
	}

	if(pthread_join (mythread, NULL)){     // 해당 스레드 코드에서 생성된 스레드가 종료될 때 까지 기다리며,
                                        // 스레드가 종료되면 자원을 해제하는 역할을 함
    // 1. 스레드의 식별자  2. 종료된 스레드에서 반환한 값을 받을 변수
    // 성공적으로 스레드가 종료되면 0을 반환받음
    // 실패 시 에러코드를 반환 받음
		printf("error joining thread.");                
		abort();                           // 프로그램을 즉시 종료시키는 함수  
	}                                    // 프로그램의 상태는 정상적으로 종료되지 않았음을 알리는 비정상 종료 코드(abort code)와 함께 운영 체제에게 반환
	printf("\nmyglobal equals %d\n", myglobal);       //전역변수 myglobal의 값을 출력하며
	exit(0);         // C 프로그램을 종료시키는 함수
  // 성공적으로 종료되면 0을 반환 + 현재 실행중인 프로세스가 메모리에서 제거되며 관련된 리소스가 전부 해제됨
  // exit(1) - 프로세스가 비정상적 종료
  // exit(-1) - 예기치 않은 종료 상황을 나타냄
}


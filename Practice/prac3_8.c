#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int n = 10, m = 100;
	int sum = 0;
	int status;

	pid = fork(); // 자식 프로세스 생성  

	if (pid > 0) { // 부모 프로세스 코드  		
		wait(&status); // 자식프로세스 종료 대기. status에 종료 코드 받음
		
		if (WEXITSTATUS(status) == 0)
			printf("부모 프로세스 : 1000보다 작다.\n");
    
		else if (WEXITSTATUS(status) == 1)
			printf("부모 프로세스 : 1000이다.\n");
    
		else if (WEXITSTATUS(status) == 2)
			printf("부모 프로세스 : 1000보다 크다.\n");
		
		return 0;
	}
  
	else if (pid == 0) { // 자식 프로세스 코드  
		sum = (n + m) * (m - n + 1) / 2;		//가우스 공식 사용

		printf("자식 프로세스 : %d에서 %d까지의 합은 %d\n", n, m, sum);

		if (sum < 1000)			//1000보다 작으면 0리턴
			return 0;
    
		else if (sum == 1000)	//1000이면 1리턴
			return 1;
    
		else					//1000보다 크면 2리턴
			return 2;
	}
  
	else { // fork() 오류 
		printf("fork 오류\n");
		return 0;
	}
}

